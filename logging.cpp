#include "logging.h"
void Logger::info(const std::string &msg) {
    spdlog::info(msg);
    file_logger->info(msg);
}

void Logger::warn(const std::string &msg) {
    spdlog::warn(msg);
    file_logger->warn(msg);
}

void Logger::debug(const std::string &msg) {
    spdlog::debug(msg);
    file_logger->debug(msg);
}

void Logger::error(const std::string &msg) {
    spdlog::error(msg);
    error_logger->error(msg);
}
