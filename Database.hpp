#pragma once

#include <mutex>
#include <iostream>
#include <map>
#include <queue>

#include <regex>

#include "DatabaseEntry.hpp"

namespace Database
{

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

        void create_entry(
            const Data::DatabaseEntryMandatoryFields& aDatabaseEntryMandatoryFields,
            const Data::DatabaseEntryOptionalFields& aDatabaseEntryOptionalFields = Data::DatabaseEntryOptionalFields());

        void search_entries(const std::regex& aRegex);

    protected:
        /// Constructors and Destructors ///

        //! Can only be constructed from GetInstance()
        Database() = default;

        //! Cannot be destroyed from outside of class
        ~Database();

    private:

        int determine_key_for_new_entry();
        int determine_largest_key_currently_in_database();

        static std::map<unsigned int, Data::DatabaseEntry> _database;
        static std::queue<unsigned int> _database_available_keys;
        
        static Database* _pinstance;
        static std::mutex _mutex;
    };

}