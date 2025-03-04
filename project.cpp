#include "logging.h"
int main() {
    // Create a global object for logging
    Logger spdlog_;

    // Test logs
    spdlog_.info("Welcome to spdlog with classes!");
    spdlog_.warn("This is a warning message");
    spdlog_.debug("This is a debug message");
    spdlog_.error("This is an error message");

    return 0;
}
