#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int main() {
    auto logger = spdlog::basic_logger_mt("file_logger", "logs.txt");
    spdlog::set_default_logger(logger);  // Set logger as default

    spdlog::info("Logging to a file now!");
    spdlog::warn("This is a warning in logs.txt");
    spdlog::error("Error logged!");

    return 0;
}
