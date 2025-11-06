#pragma once
#include <string>
#include <iostream>

namespace RenderCore {
namespace Utils {

class Logger {
public:
    static void Info(const std::string& message);
    static void Warning(const std::string& message);
    static void Error(const std::string& message);
};

}
}
