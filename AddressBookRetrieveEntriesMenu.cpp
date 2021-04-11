#include "ConsoleMenu.hpp"

#include "Database.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <regex>

namespace Menu
{
    std::shared_ptr<Data::ConsoleMenuResults> AddressBookRetrieveEntriesMenu::run()
    {
        std::shared_ptr<Data::AddressBookRetrieveEntriesMenuResults> aResults
            = std::make_shared<Data::AddressBookRetrieveEntriesMenuResults>();

		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening Retrieve Entries menu.";

			std::cout << "Enter search term:" << "\n";

			std::string search;
			std::cin >> search;

			std::regex database_regex(search,
								  std::regex_constants::ECMAScript | std::regex_constants::icase);

			Database::Database::GetInstance()->search_entries(database_regex);

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
