#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{
	std::vector<int> Menu::AddressBookOptionalMenu::get_options_passed(const std::string& aOption)
	{
		BOOST_LOG_TRIVIAL(debug) << "Parsing optional menu options";
		
		std::stringstream ss(aOption);
		std::vector<int> aReturnVector;

		while(ss.good())
		{
			std::string substr;
			getline(ss, substr, ',');
			substr.erase(std::remove(substr.begin(), substr.end(), ' '), substr.end());

			bool has_only_digits = (substr.find_first_not_of("0123456789") == std::string::npos);

			if(has_only_digits)
				aReturnVector.push_back(std::stoi(substr));
			else
			{
				BOOST_LOG_TRIVIAL(warning) << "Found an invalid option when trying to determine optional parameters: " << substr;
			}
		}

		return aReturnVector;

		BOOST_LOG_TRIVIAL(debug) << "Finished parsing optional menu options";
	}
	
	std::shared_ptr<Data::ConsoleMenuResults> Menu::AddressBookOptionalMenu::run()
    {
        auto aResults = std::make_shared<Data::AddressBookOptionalMenuResults>();

		try
		{
			BOOST_LOG_TRIVIAL(debug) << "Opening optional menu.";

			std::cout << "Enter which optional elements you would like to include, separated by a comma (,):" << "\n";
			std::cout << "1. Phone number" << "\n";
			std::cout << "2. Email" << "\n";
			std::cout << "3. Exit" << "\n";

			std::string option_in;
			std::cin >> option_in;

			std::vector<int> options_passed = get_options_passed(option_in);

			for(int option : options_passed)
			{
				if(option == 1)
				{
					std::cout << "Enter phone number:" << "\n";

					std::cin >> aResults->phone_number;
				}
				else if(option == 2)
				{
					std::cout << "Enter email:" << "\n";

					std::cin >> aResults->email;
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
			}

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
