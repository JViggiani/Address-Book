#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{
    std::unique_ptr<Data::ConsoleMenuResults> Menu::AddressBookOptionalMenu::run()
    {
        std::unique_ptr<Data::AddressBookOptionalMenuResults> aResults
            = std::make_unique<Data::AddressBookOptionalMenuResults>(Data::AddressBookOptionalMenuResults());

        return aResults;
    }
}
