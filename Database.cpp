#include "Database.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <boost/log/trivial.hpp>

namespace Database
{

    Database* Database::_pinstance{nullptr};
    std::mutex Database::_mutex;
    std::map<unsigned int, Data::DatabaseEntry> Database::_database;
    std::queue<unsigned int> Database::_database_available_keys;

    Database* Database::GetInstance()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if(_pinstance == nullptr)
        {
            _pinstance = new Database();
        }
        return _pinstance;
    }

    void Database::create_entry(
        const Data::DatabaseEntryMandatoryFields& aDatabaseEntryMandatoryFields, 
        const Data::DatabaseEntryOptionalFields& aDatabaseEntryOptionalFields)
    {
        Data::DatabaseEntry aDatabaseEntry(aDatabaseEntryMandatoryFields, aDatabaseEntryOptionalFields);

        int key = determine_key_for_new_entry();

        if(_database.insert(std::pair<int, Data::DatabaseEntry>(key, aDatabaseEntry)).second == false)
        {
            std::string aErrorMessage = "Failed to insert an entry into the database, please investigate: " + aDatabaseEntry.get_string();
            throw std::exception(aErrorMessage.c_str());
        }

        std::cout << "Inserted entry into DB." << "\n";
    }

    void Database::search_entries(const std::regex& aRegex)
    {
        for(auto iter = _database.begin(); iter != _database.end(); iter++)
        {
            if(std::regex_search(iter->second._mandatoryFields.first_name, aRegex)
                   || std::regex_search(iter->second._mandatoryFields.last_name, aRegex))
            {
                std::cout << "ENTRY KEY: " << std::to_string(iter->first) << "\n";
                std::cout << "ENTRY VALUE: " << iter->second.get_string() << "\n";
            }
        }
    }

    Database::~Database()
    {
        delete _pinstance;
    }

    int Database::determine_key_for_new_entry()
    {
        if(_database.empty())
            return 0;
        else if(_database_available_keys.empty())
        {
            return determine_largest_key_currently_in_database() + 1;
        }
        else
        {
            int aReturn = _database_available_keys.front();
            _database_available_keys.pop();
            return aReturn;
        }
    }
    int Database::determine_largest_key_currently_in_database()
    {
        return _database.rbegin()->first;
    }
}