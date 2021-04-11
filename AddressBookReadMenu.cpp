#include "ConsoleMenu.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{

	std::shared_ptr<Menu::Data::ConsoleMenuResults> Menu::AddressBookReadMenu::run()
	{
		std::shared_ptr<Data::AddressBookReadMenuResults> aResults
			= std::make_shared<Data::AddressBookReadMenuResults>();

		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening read menu.";

			bool end = false;

			do
			{
				std::cout << "========================" << "\n";
				std::cout << "==    Read Entries    ==" << "\n";
				std::cout << "1. Retrieve Settings" << "\n";
				std::cout << "2. Change Settings" << "\n";
				std::cout << "3. Retrieve Entries" << "\n";
				std::cout << "4. Exit" << "\n";
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
					//Build and run mandatory menu
					Menu::AddressBookRetrieveEntriesMenu aRetrieveEntriesMenu;
					std::shared_ptr<Menu::Data::AddressBookRetrieveEntriesMenuResults> aRetrieveEntriesResults =
						std::dynamic_pointer_cast<Menu::Data::AddressBookRetrieveEntriesMenuResults>(aRetrieveEntriesMenu.run());
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

			BOOST_LOG_TRIVIAL(debug) << "Closing read menu.";


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