#include "ConsoleMenu.hpp"
#include "Database.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{

	std::unique_ptr<Data::ConsoleMenuResults> AddressBookCreateMenu::run()
	{
		auto aResults 
			= std::make_unique<Data::AddressBookCreateMenuResults>();
		
		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening create menu.";
			
			bool end = false;

			do
			{
				std::cout << "========================" << "\n";
				std::cout << "==    Create Entry    ==" << "\n";
				std::cout << "Would you like to input any optional entries?" << "\n";
				std::cout << "1. Yes" << "\n";
				std::cout << "2. No" << "\n";
				std::cout << "3. Exit" << "\n";
				std::cout << "========================" << "\n";

				int option;
				std::cin >> option;

				Database::Data::DatabaseEntryOptionalFields aOptionalFields;

				if(option == 1)
				{
					//Build and run optional menu
					Menu::AddressBookOptionalMenu aOptionalMenu;

					std::unique_ptr<Menu::Data::AddressBookOptionalMenuResults> aOptionalResults(
						std::move(dynamic_cast<Menu::Data::AddressBookOptionalMenuResults*>(aOptionalMenu.run().get())));
					
				}
				else if(option == 2)
				{

				}
				else if(option == 3)
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
		catch(...)
		{

		}

		return aResults;
	}

}