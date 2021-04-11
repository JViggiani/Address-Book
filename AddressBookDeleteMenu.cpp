#include "ConsoleMenu.hpp"

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

		return aResults;
	}
}