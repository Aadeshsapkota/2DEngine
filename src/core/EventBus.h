#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>

class EventBus
{
public:
    template<typename T>
    static void Subscribe(std::function<void(const T&)> handler)
    {
        auto& handlers = s_Handlers[typeid(T)];
        handlers.push_back(
            [handler](const void* e)
            {
                handler(*static_cast<const T*>(e));
            }
        );
    }

    template<typename T>
    static void Emit(const T& event)
    {
        auto it = s_Handlers.find(typeid(T));
        if (it == s_Handlers.end()) return;

        for (auto& fn : it->second)
        {
            fn(&event);
        }
    }

private:
    static inline std::unordered_map<
        std::type_index,
        std::vector<std::function<void(const void*)>>
    > s_Handlers;
};
