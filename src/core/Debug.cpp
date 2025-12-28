#include "Time.h"
#include "Debug.h"
#include "raylib.h"

void Debug::Render()
{
  DrawFPS(10, 10);
  float dt = Time::DeltaTime();
  float ms = dt * 1000.0f;

  DrawText(TextFormat("Delta Time: %.4f", dt), 10, 30, 18, GREEN);
  DrawText(TextFormat("Frame Time: %.2f ms", ms), 10, 50, 18, YELLOW);
  DrawText("Engine: Aether2D", 10, 70, 18, SKYBLUE);
}
