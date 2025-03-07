#ifndef LOGGER_H
#define LOGGER_H
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
    void info(const std::string &msg);
    
    void warn(const std::string &msg);    
    void debug(const std::string &msg);
    
    void error(const std::string &msg);
    private:
    std::shared_ptr<spdlog::logger> console_logger;
    std::shared_ptr<spdlog::logger> error_logger;
    std::shared_ptr<spdlog::logger> file_logger;
    std::shared_ptr<spdlog::logger> rotating_logger;
};
#endif