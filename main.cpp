// Game Theory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "AddressBookConfig.hpp"
#include "ConsoleMenuResults.hpp"
#include "LoggingConfig.hpp"
#include "ConsoleMenu.hpp"
#include "Utils.hpp"
#include "Database.hpp"

int main(int argc, char* argv[])
{
    try
    {
        //Init logging
        Config::LoggingConfig aLoggingConfig;
        Utils::init_logging(aLoggingConfig);
        
        BOOST_LOG_TRIVIAL(debug) << "Beginning main.";

        //Build and run address book
        //Config::AddressBookConfig aAddressBookConfig;
        Menu::AddressBookMainMenu aAddressBook;
        aAddressBook.run();

        //Utils::printMenuResults(aAddressBookResults);

        BOOST_LOG_TRIVIAL(debug) << "Finishing main.";
    }
    catch(std::exception e)
    {
        BOOST_LOG_TRIVIAL(error) << "Caught exception from main: " << e.what();
    }
    catch(...)
    {
        BOOST_LOG_TRIVIAL(error) << "Caught unknown exception from main.";
    }
}