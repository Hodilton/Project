#pragma once
#include "stdafx.h"

class BaseEntities {
public:
	virtual void ReadToConsole(vector<string>&) = 0;
	virtual void ReadForSearch() = 0;
};