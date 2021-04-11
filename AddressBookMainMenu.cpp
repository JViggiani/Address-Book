#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{
	std::unique_ptr<Data::ConsoleMenuResults> Menu::AddressBookMainMenu::run()
	{
		std::unique_ptr<Data::AddressBookMainMenuResults> aResults 
			= std::make_unique<Data::AddressBookMainMenuResults>();
		
		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening main menu.";
			
			bool end = false;

			do
			{
				std::cout << "========================" << "\n";
				std::cout << "==    Address Book    ==" << "\n";
				std::cout << "Enter Input" << "\n";
				std::cout << "1. Create entry" << "\n";
				std::cout << "2. Read entry" << "\n";
				std::cout << "3. Update entry" << "\n";
				std::cout << "4. Delete entry" << "\n";
				std::cout << "5. Exit" << "\n";
				std::cout << "========================" << "\n";

				int option;
				std::cin >> option;

				if(option == 1)
				{
					//Build and run create menu
					Menu::AddressBookCreateMenu aAddressBookCreateMenu;

					auto aAddressBookCreateMenuResults = aAddressBookCreateMenu.run();
					/*
					auto aAddressBookCreateMenuResults 
						= std::make_unique<Data::AddressBookCreateMenuResults>(
							std::move(aAddressBookCreateMenu.run()));
					*/
				}
				else if(option == 2)
				{
					//Build and run read menu
					/*
					Menu::AddressBookReadMenu aAddressBookReadMenu;
					std::unique_ptr<Data::AddressBookReadMenuResults> aAddressBookReadMenuResults
						= std::make_unique<Data::AddressBookReadMenuResults>(std::move(aAddressBookReadMenu.run()));
					*/
				}
				else if(option == 3)
				{;
					//Build and run update menu
					/*
					Menu::AddressBookUpdateMenu aAddressBookUpdateMenu;
					std::unique_ptr<Data::AddressBookUpdateMenuResults> aAddressBookUpdateMenuResults
						= std::make_unique<Data::AddressBookUpdateMenuResults>(std::move(aAddressBookUpdateMenu.run()));
					*/
				}
				else if(option == 4)
				{
					//Build and run delete menu
					/*
					Menu::AddressBookDeleteMenu aAddressBookDeleteMenu;
					std::unique_ptr<Data::AddressBookDeleteMenuResults> aAddressBookDeleteMenuResults
						= std::make_unique<Data::AddressBookDeleteMenuResults>(std::move(aAddressBookDeleteMenu.run()));
					*/
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
