#include "ConsoleMenu.hpp"
#include "Database.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{

	std::shared_ptr<Menu::Data::ConsoleMenuResults> Menu::AddressBookChangeReadSettingsMenu::run()
	{
		auto aResults
			= std::make_shared<Data::AddressBookChangeReadSettingsMenuResults>();

		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening create menu.";

			bool end = false;

			do
			{
				std::cout << "===============================" << "\n";
				std::cout << "==    Change Display mode    ==" << "\n";
				std::cout << "1. Unsorted" << "\n";
				std::cout << "2. By first name" << "\n";
				std::cout << "3. By last name" << "\n";
				std::cout << "4. Exit" << "\n";
				std::cout << "===============================" << "\n";

				int option;
				std::cin >> option;

				Database::Data::DatabaseEntryOptionalFields aOptionalFields;

				if(option >= 1 && option <= 3)
				{
					Database::Database::GetInstance()->set_sort_mode(static_cast<Database::eSortMode>(option));
				}
				else if(option == 4)
				{
					end = true;
				}
				else
				{
					std::cout << "Invalid input" << "\n";
					if(std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
				}

			} while(end == false);

			BOOST_LOG_TRIVIAL(debug) << "Closing create menu.";


		}
		catch(const std::exception& e)
		{
			BOOST_LOG_TRIVIAL(debug) << "Caught main menu std exception: " << e.what();
		}
		catch(...)
		{
			BOOST_LOG_TRIVIAL(debug) << "Caught unknown main menu exception.";
		}

		return aResults;
	}
}