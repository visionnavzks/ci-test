#include <fmt/core.h>
#include <fmt/color.h>

int main() {
    fmt::print(fmt::fg(fmt::color::green), "Hello from ci-test!\n");
    fmt::print("Built with vcpkg + CMake\n");
    fmt::print("Platform: ");
#if defined(_WIN32)
    fmt::print("Windows\n");
#elif defined(__linux__)
    fmt::print("Linux\n");
#else
    fmt::print("Unknown\n");
#endif
    return 0;
}
