#pragma once

#include <string>

namespace Menu
{
	namespace Data
	{
		// TODO1: Can these be configured such that a ConsoleMenuResults can be returned for each menu call, which can then be used to make decisions on return?
		struct ConsoleMenuResults
		{
		public:
			virtual std::string get_result_string() = 0;
		private:
			//Not constructable, only a parent for other results
			ConsoleMenuResults();
		};

		struct AddressBookResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				return aResultString;
			}
		};
	}
}

