#include "ConsoleMenu.hpp"


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace Menu
{

    std::unique_ptr<Data::ConsoleMenuResults> Menu::AddressBookReadMenu::run()
    {
        std::unique_ptr<Data::AddressBookReadMenuResults> aResults
            = std::make_unique<Data::AddressBookReadMenuResults>();

        return aResults;
    }

}