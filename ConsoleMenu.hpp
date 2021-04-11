#pragma once

#include "ConsoleMenuResults.hpp"

#include <memory>
#include <iostream>

#include <vector>

namespace Menu
{

	class ConsoleMenu
	{
	public:

		///	Functions ///

		// This contains the menu program loop
		// TODO1: Consider return type, is any data needed to be returned, such as a polymorphic Results object?
		virtual std::shared_ptr<Data::ConsoleMenuResults> run() = 0;
	};

	class AddressBookMainMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookMainMenu() = default;

		//! Default destructor.
		~AddressBookMainMenu() = default;

		//! Default copy constructor
		AddressBookMainMenu(const AddressBookMainMenu&) = default;

		//! Default move constructor
		AddressBookMainMenu(AddressBookMainMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookMainMenu& operator=(const AddressBookMainMenu&) = default;

		//! Default move assignment
		AddressBookMainMenu& operator=(AddressBookMainMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;

	};

	class AddressBookCreateMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookCreateMenu() = default;

		//! Default destructor.
		~AddressBookCreateMenu() = default;

		//! Default copy constructor
		AddressBookCreateMenu(const AddressBookCreateMenu&) = default;

		//! Default move constructor
		AddressBookCreateMenu(AddressBookCreateMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookCreateMenu& operator=(const AddressBookCreateMenu&) = default;

		//! Default move assignment
		AddressBookCreateMenu& operator=(AddressBookCreateMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;
	};

	class AddressBookReadMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookReadMenu() = default;

		//! Default destructor.
		~AddressBookReadMenu() = default;

		//! Default copy constructor
		AddressBookReadMenu(const AddressBookReadMenu&) = default;

		//! Default move constructor
		AddressBookReadMenu(AddressBookReadMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookReadMenu& operator=(const AddressBookReadMenu&) = default;

		//! Default move assignment
		AddressBookReadMenu& operator=(AddressBookReadMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;
	};

	class AddressBookUpdateMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookUpdateMenu() = default;

		//! Default destructor.
		~AddressBookUpdateMenu() = default;

		//! Default copy constructor
		AddressBookUpdateMenu(const AddressBookUpdateMenu&) = default;

		//! Default move constructor
		AddressBookUpdateMenu(AddressBookUpdateMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookUpdateMenu& operator=(const AddressBookUpdateMenu&) = default;

		//! Default move assignment
		AddressBookUpdateMenu& operator=(AddressBookUpdateMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;
	};

	class AddressBookDeleteMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookDeleteMenu() = default;

		//! Default destructor.
		~AddressBookDeleteMenu() = default;

		//! Default copy constructor
		AddressBookDeleteMenu(const AddressBookDeleteMenu&) = default;

		//! Default move constructor
		AddressBookDeleteMenu(AddressBookDeleteMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookDeleteMenu& operator=(const AddressBookDeleteMenu&) = default;

		//! Default move assignment
		AddressBookDeleteMenu& operator=(AddressBookDeleteMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;
	};	

	class AddressBookOptionalMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookOptionalMenu() = default;

		//! Default destructor.
		~AddressBookOptionalMenu() = default;

		//! Default copy constructor
		AddressBookOptionalMenu(const AddressBookOptionalMenu&) = default;

		//! Default move constructor
		AddressBookOptionalMenu(AddressBookOptionalMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookOptionalMenu& operator=(const AddressBookOptionalMenu&) = default;

		//! Default move assignment
		AddressBookOptionalMenu& operator=(AddressBookOptionalMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;

	private:
		std::vector<int> get_options_passed(const std::string& aOption);

	};

	class AddressBookMandatoryMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookMandatoryMenu() = default;

		//! Default destructor.
		~AddressBookMandatoryMenu() = default;

		//! Default copy constructor
		AddressBookMandatoryMenu(const AddressBookMandatoryMenu&) = default;

		//! Default move constructor
		AddressBookMandatoryMenu(AddressBookMandatoryMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookMandatoryMenu& operator=(const AddressBookMandatoryMenu&) = default;

		//! Default move assignment
		AddressBookMandatoryMenu& operator=(AddressBookMandatoryMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;

	};

	class AddressBookRetrieveEntriesMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookRetrieveEntriesMenu() = default;

		//! Default destructor.
		~AddressBookRetrieveEntriesMenu() = default;

		//! Default copy constructor
		AddressBookRetrieveEntriesMenu(const AddressBookRetrieveEntriesMenu&) = default;

		//! Default move constructor
		AddressBookRetrieveEntriesMenu(AddressBookRetrieveEntriesMenu&&) = default;

		///	Operators ///

		//! Default copy assignment
		AddressBookRetrieveEntriesMenu& operator=(const AddressBookRetrieveEntriesMenu&) = default;

		//! Default move assignment
		AddressBookRetrieveEntriesMenu& operator=(AddressBookRetrieveEntriesMenu&&) = default;

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		std::shared_ptr<Data::ConsoleMenuResults> run() final;

	};

	
}