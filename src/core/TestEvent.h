#include"Event.h"

struct TestEvent : public Event {
    int value;
    TestEvent(int v) : value(v) {}
};
