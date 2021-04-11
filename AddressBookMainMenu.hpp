#pragma once

#include "AddressBookConfig.hpp"
#include "ConsoleMenuResults.hpp"
#include "ConsoleMenu.hpp"

#include <set>

namespace Menu
{

	class AddressBookMainMenu : public Menu::ConsoleMenu
	{
	public:

		///	Constructors and Destructors ///

		//! Main constructor.
		AddressBookMainMenu(const Config::AddressBookConfig& aAddressBookConfig);

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
		AddressBookMainMenu& operator=(AddressBookMainMenu&&);

		///	Functions ///

		// This contains the main program loop and controls the upper menu level
		void run();
	};
}