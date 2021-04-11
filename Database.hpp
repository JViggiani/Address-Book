#pragma once

#include <mutex>
#include <iostream>
#include <map>
#include <stack>

#include <regex>

#include "DatabaseEntry.hpp"

namespace Database
{
    // An enum to track how the database should display search entries
    enum class eSortMode
    {
        Unsorted,
        FirstName,
        LastName
    }; // enum class

    //! The Database is a thread safe Singleton which handles the connection to the database
    class Database
    {
    public:
        /// Constructors and Destructors ///

        //! Singletons should not be cloneable.
        Database(Database& other) = delete;

        //! Deleted move constructor
        Database(Database&&) = delete;

        /// Operators ///

        //! Singletons should not be assignable.
        void operator=(const Database&) = delete;

        //! Singletons should not be moveable.
        Database& operator=(Database&&) = delete;

        /// Functions ///

        //! This is the static method that controls the access to the singleton instance. It gaurantees that only one instance is ever made.
        static Database* GetInstance();

        // Creates a new entry in the database
        void create_entry(
            const Data::DatabaseEntryMandatoryFields& aDatabaseEntryMandatoryFields,
            const Data::DatabaseEntryOptionalFields& aDatabaseEntryOptionalFields = Data::DatabaseEntryOptionalFields());

        // Searches the database mandatory first_name and last_name field values for terms which match the provided regex 
        void search_entries(const std::regex& aRegex);

        // Deletes the key and associated value from the database
        void delete_entry(unsigned int key);

        eSortMode get_sort_mode();
        void set_sort_mode(eSortMode aSortMode);

    protected:
        /// Constructors and Destructors ///

        //! Can only be constructed from GetInstance()
        Database() = default;

        //! Cannot be destroyed from outside of class
        ~Database();

    private:

        // Determines the most appropriate key to use for the next database insertion. Automatically calculates how to fill key holes in the database
        unsigned int determine_key_for_new_entry();

        // Returns the largest key currently in the database
        unsigned int determine_largest_key_currently_in_database();

        // The database object itself: a unique key and a non-unique value. 
        static std::map<unsigned int, Data::DatabaseEntry> _database;

        // A stack of available keys to use from previous deletions
        static std::stack<unsigned int> _database_available_keys;
        
        static Database* _pinstance;
        static std::mutex _mutex;

        // Tracks how to sort results upon performing a regex search with search_entries()
        static eSortMode _sortMode;
    };

    // Comparitor for sorting searched entries, used for eSortMode::FirstName
    struct CompareByFirstName
    {
        bool operator()(const Data::DatabaseEntry& a, const Data::DatabaseEntry& b) const
        {
            return a._mandatoryFields.first_name < b._mandatoryFields.first_name;
        }
    };

    // Comparitor for sorting searched entries, used for eSortMode::LastName
    struct CompareByLastName
    {
        bool operator()(const Data::DatabaseEntry& a, const Data::DatabaseEntry& b) const
        {
            return a._mandatoryFields.last_name < b._mandatoryFields.last_name;
        }
    };
}