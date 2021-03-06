#include "ConsoleMenu.hpp"

#include "Database.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{

	std::shared_ptr<Menu::Data::ConsoleMenuResults> Menu::AddressBookDeleteMenu::run()
	{
		auto aResults
			= std::make_shared<Data::AddressBookDeleteMenuResults>();

		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening delete menu.";

			bool end = false;

			do
			{
				std::cout << "========================" << "\n";
				std::cout << "==    Delete Entry    ==" << "\n";
				std::cout << "Are you sure you want to delete a key? You must know the key to delete beforehand, which can be found with the Read Entry menu." << "\n";
				std::cout << "1. Yes" << "\n";
				std::cout << "2. No, exit" << "\n";
				std::cout << "========================" << "\n";

				int option;
				std::cin >> option;

				if(option == 1)
				{
					std::cout << "Enter key to delete" << "\n";
					
					unsigned int key;
					std::cin >> key;

					Database::Database::GetInstance()->delete_entry(key);
				}
				else if(option == 2)
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