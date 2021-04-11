#include "AddressBookMainMenu.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{
	AddressBookMainMenu::AddressBookMainMenu(const Config::AddressBookConfig& aAddressBookConfig)
	{
        BOOST_LOG_TRIVIAL(debug) << "Constructing AddressBook";
	}
	
    void Menu::AddressBookMainMenu::run()
	{
		bool end = false;

		do
		{
			std::cout << "========================" << "\n";
			std::cout << "==    Address Book    ==" << "\n";
			std::cout << "Enter Input" << "\n";
			std::cout << "1. Search address book" << "\n";
			std::cout << "2. Add contacts" << "\n";
			std::cout << "3. Remove contacts" << "\n";
			std::cout << "4. View contacts" << "\n";
			std::cout << "5. Edit contacts" << "\n";
			std::cout << "6. Exit" << "\n";
			std::cout << "========================" << "\n";

			int option;
			std::cin >> option;

			if(option == 1)
			{

			}
			else if(option == 2)
			{

			}
			else if(option == 3)
			{
				
			}
			else if(option == 4)
			{

			}
			else if(option == 5)
			{

			}
			else if(option == 6)
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
	}

}
