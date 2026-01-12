
// This Engine is based of System-Based Design

#include "Application.h"
#include "Time.h"
#include "../input/Input.h"
#include "Debug.h"
#include "EventBus.h"
#include"TestEvent.h"
#include <raylib.h>

Application::Application()
{
    Init();
}

Application::~Application()
{
    Shutdown();
}

void Application::Run()
{
    while (!WindowShouldClose())
    {
        Time::Update();
        m_Accumulator += Time::DeltaTime();

        while (m_Accumulator >= Time::FixedDeltaTime())
        {
            FixedUpdate(); // fixed update to apply physics
            m_Accumulator -= Time::FixedDeltaTime();
        }

        Update(); // variable update for input , animation, logic
        Render();
    }
}

void Application::Init()
{
    InitWindow(1280, 720, "Aether2D Engine");
    SetTargetFPS(60);
    Input::Init();
    Debug::Init();
}

void Application::Shutdown()
{
    CloseWindow();
}

void Application::FixedUpdate()
{
    // physics (fixed timestep)
}

void Application::Update()
{
    Input::Update();
    static bool fired = false;

    if (!fired)
    {
        EventBus::Emit(TestEvent{42});
        fired = true;
    }
}

void Application::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);

    if (Input::GetActionState("Jump") == InputState::Pressed)
        DrawText("JUMP PRESSED", 500, 200, 20, GREEN);

    if (Input::GetActionState("Jump") == InputState::Held)
        DrawText("JUMP HELD", 500, 260, 20, RED);

    if (Input::GetActionState("MoveLeft") == InputState::Held)
        DrawText("MOVING LEFT", 500, 230, 20, YELLOW);
    if (Input::GetActionState("MoveRight") == InputState::Held)
        DrawText("MOVING RIGHT", 300, 230, 20, YELLOW);
        //test (remove later)
    // gameplay/TestGameplay.cpp
        if (IsKeyPressed(KEY_SPACE))
        {
            EventBus::Emit(TestEvent{rand() % 100});
        }
   

    Debug::Render();
    EndDrawing();
}
