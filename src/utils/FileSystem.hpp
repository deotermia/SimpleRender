#pragma once
#include <string>

namespace RenderCore {
namespace Utils {

class FileSystem {
public:
    static std::string ReadFile(const std::string& filepath);
    static bool FileExists(const std::string& filepath);
};

}
}
