#include "pch.h"
#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& message) :logic_error("Item not found: " + message)
{

}