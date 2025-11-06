#pragma once
#include "common/types.hpp"

namespace RenderCore {
namespace Rendering {

class VertexBuffer
{
public:
    VertexBuffer(const void* data, uint32 size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

private:
    uint32 m_RendererID;
};

}
}
