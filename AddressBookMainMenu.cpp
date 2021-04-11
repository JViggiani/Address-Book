#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{
	std::shared_ptr<Data::ConsoleMenuResults> Menu::AddressBookMainMenu::run()
	{
		std::shared_ptr<Data::AddressBookMainMenuResults> aResults 
			= std::make_shared<Data::AddressBookMainMenuResults>();
		
		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening main menu.";
			
			bool end = false;

			do
			{
				std::cout << "========================" << "\n";
				std::cout << "==    Address Book    ==" << "\n";
				std::cout << "Enter Input" << "\n";
				std::cout << "1. Create entries" << "\n";
				std::cout << "2. Read entries" << "\n";
				std::cout << "3. Update entries" << "\n";
				std::cout << "4. Delete entries" << "\n";
				std::cout << "5. Exit" << "\n";
				std::cout << "========================" << "\n";

				int option;
				std::cin >> option;

				if(option == 1)
				{
					//Build and run create menu
					Menu::AddressBookCreateMenu aAddressBookCreateMenu;
					std::shared_ptr<Menu::Data::AddressBookCreateMenuResults> aCreateResults =
						std::dynamic_pointer_cast<Menu::Data::AddressBookCreateMenuResults>(aAddressBookCreateMenu.run());
				}
				else if(option == 2)
				{
					//Build and run read menu
					Menu::AddressBookReadMenu aAddressBookReadMenu;
					std::shared_ptr<Menu::Data::AddressBookReadMenuResults> aReadResults =
						std::dynamic_pointer_cast<Menu::Data::AddressBookReadMenuResults>(aAddressBookReadMenu.run());
				}
				else if(option == 3)
				{
					//Build and run update menu
					Menu::AddressBookUpdateMenu aAddressBookUpdateMenu;
					std::shared_ptr<Menu::Data::AddressBookUpdateMenuResults> aUpdateResults =
						std::dynamic_pointer_cast<Menu::Data::AddressBookUpdateMenuResults>(aAddressBookUpdateMenu.run());
				}
				else if(option == 4)
				{
					//Build and run delete menu
					Menu::AddressBookDeleteMenu aAddressBookDeleteMenu;
					std::shared_ptr<Menu::Data::AddressBookDeleteMenuResults> aDeleteResults =
						std::dynamic_pointer_cast<Menu::Data::AddressBookDeleteMenuResults>(aAddressBookDeleteMenu.run());
				}
				else if(option == 5)
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
			BOOST_LOG_TRIVIAL(debug) << "Closing main menu.";

			
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
