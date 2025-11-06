#include "utils/FileSystem.hpp"
#include <fstream>
#include <sstream>

namespace RenderCore {
namespace Utils {

std::string FileSystem::ReadFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        return "";
    }
    
    std::stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

bool FileSystem::Exists(const std::string& filepath) {
    std::ifstream file(filepath);
    return file.good();
}

}
}
