#include "Time.h"
#include "Debug.h"
#include "EventBus.h"
#include "TestEvent.h"
#include "raylib.h"

// test
static int lastValue = -1;

void Debug::Init()
{
  EventBus::Subscribe<TestEvent>(
      [](const TestEvent &e)
      {
        TraceLog(LOG_INFO, "TestEvent value: %d", e.value);
      });
}

void Debug::Render()
{
  DrawFPS(10, 10);
  float dt = Time::DeltaTime();
  float ms = dt * 1000.0f;

  DrawText(TextFormat("Delta Time: %.4f", dt), 10, 30, 18, GREEN);
  DrawText(TextFormat("Frame Time: %.2f ms", ms), 10, 50, 18, YELLOW);
  DrawText("Engine: Aether2D", 10, 70, 18, SKYBLUE);
  if (lastValue != -1)
  {
    DrawText(TextFormat("Event Value: %d", lastValue), 20, 20, 20, GREEN);
  }
}
