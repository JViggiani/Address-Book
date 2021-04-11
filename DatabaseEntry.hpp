#pragma once
#include "ConsoleMenuResults.hpp"

namespace Database
{
	namespace Data
	{
		struct DatabaseEntryMandatoryFields
		{
			DatabaseEntryMandatoryFields(std::string aFirstName, std::string aLastName)
				: first_name(aFirstName), last_name(aLastName)
			{
			};

			DatabaseEntryMandatoryFields(const Menu::Data::AddressBookMandatoryMenuResults& aAddressBookMandatoryMenuResults)
				: first_name(aAddressBookMandatoryMenuResults.first_name),
				last_name(aAddressBookMandatoryMenuResults.last_name)
			{
			};

			std::string get_string()
			{
				std::string aReturn;
				aReturn.append("First name: " + first_name + "\n");
				aReturn.append("Last name: " + last_name + "\n");

				return aReturn;
			};

			std::string first_name;
			std::string last_name;
		};

		struct DatabaseEntryOptionalFields
		{
			DatabaseEntryOptionalFields() = default;
			
			void operator=(const Menu::Data::AddressBookOptionalMenuResults& aAddressBookOptionalMenuResults)
			{
				phone_number = aAddressBookOptionalMenuResults.phone_number;
				email = aAddressBookOptionalMenuResults.email;
			};
			
			
			DatabaseEntryOptionalFields(const Menu::Data::AddressBookOptionalMenuResults& aAddressBookOptionalMenuResults) 
				: phone_number(aAddressBookOptionalMenuResults.phone_number),
				email(aAddressBookOptionalMenuResults.email)
			{
			};

			std::string get_string()
			{
				std::string aReturn;
				if(!phone_number.empty())
					aReturn.append("Phone number: " + phone_number + "\n");
				if(!email.empty())
					aReturn.append("Email: " + email + "\n");

				return aReturn;
			};

			std::string phone_number;
			std::string email;
		};
		
		// This describes the data which should be stored in the database.
		struct DatabaseEntry
		{
			// First name and last name are mandatory, but phone number is optional
			DatabaseEntry(const DatabaseEntryMandatoryFields& aDatabaseEntryMandatoryFields, 
						  const DatabaseEntryOptionalFields& aDatabaseEntryOptionalFields = DatabaseEntryOptionalFields())
				:	_mandatoryFields(aDatabaseEntryMandatoryFields),
					_optionalFields(aDatabaseEntryOptionalFields)
			{
			};

			std::string get_string()
			{
				std::string aReturn;

				aReturn.append(_mandatoryFields.get_string());
				aReturn.append(_optionalFields.get_string());

				return aReturn;
			};
			
			DatabaseEntryMandatoryFields _mandatoryFields;
			DatabaseEntryOptionalFields _optionalFields;
		};
	}
}