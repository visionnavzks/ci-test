# ci-test

A C++ project using [vcpkg](https://vcpkg.io/) for dependency management, with GitHub Actions CI that automatically builds and packages binaries for **Ubuntu** and **Windows** on every push.

## Dependencies

- [fmt](https://github.com/fmtlib/fmt) – modern C++ formatting library (managed via vcpkg)

## Build Locally

### Prerequisites

- CMake ≥ 3.20
- Ninja
- vcpkg (with `VCPKG_ROOT` environment variable set)

### Steps

```bash
# Clone and bootstrap vcpkg (if not already done)
git clone https://github.com/microsoft/vcpkg "$VCPKG_ROOT"
"$VCPKG_ROOT/bootstrap-vcpkg.sh"   # Linux/macOS
# or
"%VCPKG_ROOT%\bootstrap-vcpkg.bat" # Windows

# Configure & Build (Linux)
cmake --preset linux-release
cmake --build --preset linux-release

# Configure & Build (Windows)
cmake --preset windows-release
cmake --build --preset windows-release

# Package
cd build/linux-release   # or build/windows-release
cpack
```

## CI

GitHub Actions runs on every push and pull request.  
Artifacts (`.tar.gz` for Linux, `.zip` for Windows) are uploaded for each run.