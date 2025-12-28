#pragma once

class Time{
  public:
      static float DeltaTime();
      static float FixedDeltaTime();

      static void Update();
  private:
  static float s_DeltaTime;
  static float s_LastFrameTime;
  static constexpr float s_FixedDelta = 1.0f/60.0f;
};