extern crate bindgen;

use std::env;
use std::path::PathBuf;

fn main() {
    println!("cargo:rerun-if-changed=src/c99.h");
    println!("cargo:rerun-if-changed=build.rs");

    let pointer_width = env::var("CARGO_CFG_TARGET_POINTER_WIDTH").unwrap();

    let file = PathBuf::from("src").join("c99.h");

    let mut builder = bindgen::Builder::default()
        .header(file.to_string_lossy())
        .clang_arg(format!("-m{pointer_width}"))
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()));

    if env::var("CARGO_FEATURE_STD").is_err() {
        builder = builder.use_core();
    }

    let bindings = builder.generate().expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
