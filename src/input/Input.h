#pragma once
#include <unordered_map>
#include <string>

enum class InputState
{
    None,
    Pressed,
    Held,
    Released
};

class Input
{
public:
    static void Init();
    static void Update();

    static bool GetAction(const std::string& action);
    static InputState GetActionState(const std::string& action);
private:
    static void UpdateKey(int key, InputState& state);
    static std::unordered_map<std::string, int> s_ActionMap;
    static std::unordered_map<int, InputState> s_KeyStates;
};
