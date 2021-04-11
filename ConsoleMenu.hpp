#pragma once

#include "ConsoleMenuResults.hpp"

#include <memory>

namespace Menu
{

	class ConsoleMenu
	{
	public:

		///	Functions ///

		// This contains the menu program loop
		// TODO1: Consider return type, is any data needed to be returned, such as a polymorphic Results object?
		virtual void run() = 0;
	};

}