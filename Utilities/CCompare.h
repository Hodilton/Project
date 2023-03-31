#pragma once

class Compare {
public:
	Compare() {
		current_state = 5;
	}

	unsigned short GetState() {
		return current_state;
	}

	void SwitchState(unsigned short state) {
		current_state = state;
	}

private:
	enum class StateCmp { First = 1, Last = 2, Middle = 4, Pass = 5 };
	unsigned short current_state;
};