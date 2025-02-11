#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
using namespace spdlog;

int main() {
    // Log a simple message
    spdlog::info("Welcome to spdlog!");

    // Log with formatting
    spdlog::warn("This is a warning with a number: {}", 42);

    // Change the global log level to debug
    spdlog::set_level(spdlog::level::debug);
    spdlog::debug("This is a debug message");
    
    // Set a custom log pattern
    spdlog::set_pattern("[%H:%M:%S] [%l] %v");
    spdlog::info("This is an info message with a custom pattern");

    // Create a file logger
    auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    file_logger->info("This is a log message in a file");

    // Create a rotating file logger with a maximum size of 5 MB and 3 rotated files
    auto rotating_logger = spdlog::rotating_logger_mt("rotating_logger", "logs/rotating-log.txt", 1048576 * 5, 3);
    rotating_logger->info("This is a rotating log message");


    // Enable asynchronous mode with a queue size of 8192
    //spdlog::init_thread_pool(8192, 1);
    //auto async_file_logger = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async-log.txt");
    //async_file_logger->info("This is an asynchronous log message");
 // create a color multi-threaded logger
    auto console = spdlog::stdout_color_mt("console");    
    auto err_logger = spdlog::stderr_color_mt("stderr");    
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
    return 0;
}