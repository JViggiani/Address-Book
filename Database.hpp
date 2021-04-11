#pragma once

#include <mutex>
#include <iostream>
#include <map>
#include <queue>

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

    protected:
        /// Constructors and Destructors ///

        //! Can only be constructed from GetInstance()
        Database() = default;

        //! Cannot be destroyed from outside of class
        ~Database();

    private:

        static std::map<unsigned int, Data::DatabaseEntry> database_;

        static std::queue<unsigned int> database_available_keys_;

        static unsigned int largest_key_;

        static Database* pinstance_;
        static std::mutex mutex_;
    };

}