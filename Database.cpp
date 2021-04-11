#include "Database.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <boost/log/trivial.hpp>


namespace Database
{

    Database* Database::_pinstance{nullptr};
    std::mutex Database::_mutex;
    std::map<unsigned int, Data::DatabaseEntry> Database::_database;
    std::stack<unsigned int> Database::_database_available_keys;
    eSortMode Database::_sortMode = eSortMode::Unsorted;

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

    eSortMode Database::get_sort_mode()
    {
        return _sortMode;
    }
    void Database::set_sort_mode(eSortMode aSortMode)
    {
        std::cout << "Changed sort mode: " << std::to_string(static_cast<typename std::underlying_type<eSortMode>::type>(aSortMode)) << "\n";
        
        _sortMode = aSortMode;
    }

    void Database::search_entries(const std::regex& aRegex)
    {
        if(Database::GetInstance()->get_sort_mode() == eSortMode::Unsorted)
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
        else if(Database::GetInstance()->get_sort_mode() == eSortMode::FirstName)
        {
            //Keys and values are reversed here to remain in the desired order
            std::multimap<Data::DatabaseEntry, unsigned int, CompareByFirstName> aSearchMap;

            for(auto iter = _database.begin(); iter != _database.end(); iter++)
            {
                if(std::regex_search(iter->second._mandatoryFields.first_name, aRegex)
                   || std::regex_search(iter->second._mandatoryFields.last_name, aRegex))
                {


                    aSearchMap.insert(std::pair<Data::DatabaseEntry, unsigned int>(iter->second, iter->first));
                }
            }

            for(auto& element : aSearchMap)
            {                
                std::cout << "ENTRY KEY: " << std::to_string(element.second) << "\n";
                std::cout << "ENTRY VALUE: " << element.first.get_string() << "\n";
            }
        }
        else if(Database::GetInstance()->get_sort_mode() == eSortMode::LastName)
        {
            //Keys and values are reversed here to remain in the desired order
            std::multimap<Data::DatabaseEntry, unsigned int, CompareByLastName> aSearchMap;

            for(auto iter = _database.begin(); iter != _database.end(); iter++)
            {
                if(std::regex_search(iter->second._mandatoryFields.first_name, aRegex)
                   || std::regex_search(iter->second._mandatoryFields.last_name, aRegex))
                {
                    //std::cout << "ENTRY KEY: " << std::to_string(iter->first) << "\n";
                    //std::cout << "ENTRY VALUE: " << iter->second.get_string() << "\n";

                    aSearchMap.insert(std::pair<Data::DatabaseEntry, unsigned int>(iter->second, iter->first));
                }
            }

            for(auto& element : aSearchMap)
            {
                std::cout << "ENTRY KEY: " << std::to_string(element.second) << "\n";
                std::cout << "ENTRY VALUE: " << element.first.get_string() << "\n";
            }
        }
        else
        {
            throw std::exception("Unknown setting on how to sort retrieval output");
        }
    }

    void Database::delete_entry(unsigned int key)
    {
        auto aMapIt = _database.find(key);

        if(aMapIt != _database.end())
        {
            std::cout << "Deleting key: " << std::to_string(key) << "\n";
            std::cout << "Deleting entry: " << aMapIt->second.get_string() << "\n";

            _database.erase(key);

            _database_available_keys.push(key);
        }
        else
        {
            std::cout << "Could not find key to delete." << "\n";
        }
    }

    Database::~Database()
    {
        delete _pinstance;
    }

    unsigned int Database::determine_key_for_new_entry()
    {
        if(_database.empty())
            return 0;
        else if(_database_available_keys.empty())
        {
            return determine_largest_key_currently_in_database() + 1;
        }
        else
        {
            unsigned int aReturn = _database_available_keys.top();
            _database_available_keys.pop();
            return aReturn;
        }
    }
    unsigned int Database::determine_largest_key_currently_in_database()
    {
        return _database.rbegin()->first;
    }
}