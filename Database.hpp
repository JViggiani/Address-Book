#pragma once

#include <mutex>
#include <iostream>

namespace Core
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

        //JOSH TODO add members here to initialise database, update members etc etc
        

    protected:
        /// Constructors and Destructors ///

        //! Can only be constructed from GetInstance()
        Database() = default;

        //! Cannot be destroyed from outside of class
        ~Database();

    private:

        static Database* pinstance_;
        static std::mutex mutex_;
    };

}