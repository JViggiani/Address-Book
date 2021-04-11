#include "AddressBookConfig.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Config
{
	
	Config::AddressBookConfig::AddressBookConfig()
	{
		BOOST_LOG_TRIVIAL(debug) << "Reading Tournament config";
		
	}
}


