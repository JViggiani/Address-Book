#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{
    std::unique_ptr<Data::ConsoleMenuResults> Menu::AddressBookUpdateMenu::run()
    {
        std::unique_ptr<Data::AddressBookUpdateMenuResults> aResults
            = std::make_unique<Data::AddressBookUpdateMenuResults>();

        return aResults;
    }
}
