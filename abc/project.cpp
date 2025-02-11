#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"


class Logger {
public:
    Logger() {
        // Set global log level
        spdlog::set_level(spdlog::level::debug);

        // Set a custom log pattern
        spdlog::set_pattern("[%H:%M:%S] [%l] %v");

        // Initialize console loggers
        console_logger = spdlog::stdout_color_mt("console");
        error_logger = spdlog::stderr_color_mt("stderr");

        // Initialize file loggers
        file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
        rotating_logger = spdlog::rotating_logger_mt("rotating_logger", "logs/rotating-log.txt", 1048576 * 5, 3);
        
        spdlog::info("Logger initialized successfully!");
    }

    // Logging functions
    void info(const std::string &msg) {
        spdlog::info(msg);
        file_logger->info(msg);
    }

    void warn(const std::string &msg) {
        spdlog::warn(msg);
        file_logger->warn(msg);
    }

    void debug(const std::string &msg) {
        spdlog::debug(msg);
        file_logger->debug(msg);
    }

    void error(const std::string &msg) {
        spdlog::error(msg);
        error_logger->error(msg);
    }

private:
    std::shared_ptr<spdlog::logger> console_logger;
    std::shared_ptr<spdlog::logger> error_logger;
    std::shared_ptr<spdlog::logger> file_logger;
    std::shared_ptr<spdlog::logger> rotating_logger;
};




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
