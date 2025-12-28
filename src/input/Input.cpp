#include "Input.h"
#include <raylib.h>

// Static member definitions
std::unordered_map<std::string, int> Input::s_ActionMap;
std::unordered_map<int, InputState> Input::s_KeyStates;

void Input::Init()
{
    // Action → Key mapping
    s_ActionMap["MoveLeft"]  = KEY_A;
    s_ActionMap["MoveRight"] = KEY_D;
    s_ActionMap["Jump"]      = KEY_SPACE;

    // Initialize key states
    for (const auto& [action, key] : s_ActionMap)
    {
        s_KeyStates[key] = InputState::None;
    }
}

void Input::Update()
{
    for (auto& [key, state] : s_KeyStates)
    {
        UpdateKey(key, state);
    }
}

void Input::UpdateKey(int key, InputState& state)
{
    if (IsKeyPressed(key))
    {
        state = InputState::Pressed;
    }
    else if (IsKeyDown(key))
    {
        state = InputState::Held;
    }
    else if (IsKeyReleased(key))
    {
        state = InputState::Released;
    }
    else
    {
        state = InputState::None;
    }
}

bool Input::GetAction(const std::string& action)
{
    auto it = s_ActionMap.find(action);
    if (it == s_ActionMap.end())
        return false;

    InputState state = s_KeyStates[it->second];
    return state == InputState::Pressed || state == InputState::Held;
}

InputState Input::GetActionState(const std::string& action)
{
    auto it = s_ActionMap.find(action);
    if (it == s_ActionMap.end())
        return InputState::None;

    return s_KeyStates[it->second];
}
