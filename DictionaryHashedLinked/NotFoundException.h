#pragma once
#include "pch.h"
#include <stdexcept>
#include <string>

using namespace std;
class NotFoundException :public logic_error
{
public:
		NotFoundException(const string& message = "");

};