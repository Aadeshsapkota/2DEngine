
#include"Time.h"
#include<raylib.h>
float Time::s_DeltaTime = 0.0f;
float Time::s_LastFrameTime= 0.0f;

float Time::DeltaTime(){
  return s_DeltaTime;
}

float Time::FixedDeltaTime(){
  return s_FixedDelta;
}

void Time::Update(){
  float currentTime = GetTime();
  s_DeltaTime = currentTime - s_LastFrameTime;
  s_LastFrameTime = currentTime;

  //clamp to avoid spiral of death
  if(s_DeltaTime > 0.25f){
    s_DeltaTime = 0.25f;
  }
}

