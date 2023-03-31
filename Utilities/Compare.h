#pragma once
#include "stdafx.h"

class Compare {
public:
    static const string& GetState() {
        return _current_state;
    }

    static void SwitchState(const string& state) {
        _current_state = state;
    }

private:
    static string _current_state;
};