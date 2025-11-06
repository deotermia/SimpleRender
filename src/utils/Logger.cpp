#include "utils/Logger.hpp"
#include <iostream>

namespace RenderCore {
namespace Utils {

void Logger::Info(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}

void Logger::Warning(const std::string& message) {
    std::cout << "[WARNING] " << message << std::endl;
}

void Logger::Error(const std::string& message) {
    std::cout << "[ERROR] " << message << std::endl;
}

}
}
