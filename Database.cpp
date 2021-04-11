#include "Database.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <boost/log/trivial.hpp>

namespace Core
{

    Database* Database::pinstance_{nullptr};
    std::mutex Database::mutex_;

    Database* Database::GetInstance()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if(pinstance_ == nullptr)
        {
            pinstance_ = new Database();
        }
        return pinstance_;
    }

    Database::~Database()
    {
        delete pinstance_;
    }
}