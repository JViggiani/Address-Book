#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{

	std::shared_ptr<Data::ConsoleMenuResults> Menu::AddressBookMandatoryMenu::run()
	{
		std::shared_ptr<Data::AddressBookMandatoryMenuResults> aResults
			= std::make_shared<Data::AddressBookMandatoryMenuResults>(Data::AddressBookMandatoryMenuResults());

		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening mandatory menu.";

			std::cout << "Enter first name:" << "\n";

			std::string first_name;
			std::cin >> first_name;

			std::cout << "Enter last name:" << "\n";

			std::string last_name;
			std::cin >> last_name;

			aResults->first_name = first_name;
			aResults->last_name = last_name;

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