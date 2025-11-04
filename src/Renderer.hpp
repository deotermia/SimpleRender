#pragma once

class Renderer {
public:
    Renderer();
    ~Renderer();

    void SetClearColor(float r, float g, float b, float a);
    void Clear();
    void DrawTriangle();

private:
    unsigned int m_VAO, m_VBO;
    float m_ClearColor[4];
};
