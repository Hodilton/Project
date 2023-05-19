#pragma once
#include "stdafx.h"

class Compare {
public:
    static const string& GetState() {
        return _current_state;
    }

    static const string& GetTempState() {
        return _temp_state;
    }

    static void SwitchState(const string& state) {
        _current_state = state;
    }

    static void SwitchTempState(const string& state) {
        _temp_state = state;
    }

private:
    static string _current_state;
    static string _temp_state;
};