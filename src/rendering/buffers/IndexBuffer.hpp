#pragma once
#include "common/types.hpp"

namespace RenderCore {
namespace Rendering {

class IndexBuffer
{
public:
    IndexBuffer(const uint32* data, uint32 count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;
    uint32 GetCount() const { return m_Count; }

private:
    uint32 m_RendererID;
    uint32 m_Count;
};

}
}
