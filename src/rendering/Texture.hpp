#pragma once
#include "common/types.hpp"
#include <string>

namespace RenderCore {
namespace Rendering {

class Texture
{
public:
    Texture(const std::string& filepath);
    ~Texture();

    void Bind(uint32 slot = 0) const;
    void Unbind() const;

    uint32 GetWidth() const { return m_Width; }
    uint32 GetHeight() const { return m_Height; }

private:
    uint32 m_RendererID;
    std::string m_Filepath;
    uint32 m_Width, m_Height;
};

}
}
