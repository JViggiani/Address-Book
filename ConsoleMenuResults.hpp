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
		};

		struct AddressBookMainMenuResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				return aResultString;
			}
		};

		struct AddressBookCreateMenuResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				return aResultString;
			}
		};

		struct AddressBookReadMenuResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				return aResultString;
			}
		};

		struct AddressBookUpdateMenuResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				return aResultString;
			}
		};

		struct AddressBookDeleteMenuResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				return aResultString;
			}
		};

		struct AddressBookOptionalMenuResults : public ConsoleMenuResults
		{
			std::string get_result_string()
			{
				std::string aResultString;

				aResultString.append(phone_number);

				return aResultString;
			}

			std::string phone_number;
		};

		
	}
}

