#pragma once
#include "../input/Input.h"

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    void Init();
    void FixedUpdate(); // - FixedUpdate() runs physics at a constant rate
    void Update();      // - Update() handles input and game logic per frame
    void Render();      // - Render() draws the current state
    float m_Accumulator = 0.0f;
    void Shutdown();
};
