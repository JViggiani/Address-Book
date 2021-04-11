#pragma once
#include "ConsoleMenuResults.hpp"

namespace Database
{
	namespace Data
	{
		// A data struct containing fields which must exist in the database.
		struct DatabaseEntryMandatoryFields
		{
			DatabaseEntryMandatoryFields(std::string aFirstName, std::string aLastName)
				: first_name(aFirstName), last_name(aLastName)
			{
				if(aFirstName.empty() || aLastName.empty())
				{
					throw std::exception("Mandatory fields cannot be blank");
				}
			};

			DatabaseEntryMandatoryFields(const Menu::Data::AddressBookMandatoryMenuResults& aAddressBookMandatoryMenuResults)
				: first_name(aAddressBookMandatoryMenuResults.first_name),
				last_name(aAddressBookMandatoryMenuResults.last_name)
			{
				if(aAddressBookMandatoryMenuResults.first_name.empty() || aAddressBookMandatoryMenuResults.last_name.empty())
				{
					throw std::exception("Mandatory fields cannot be blank");
				}
			};

			// For human readable printing purposes
			std::string get_string() const
			{
				std::string aReturn;
				aReturn.append("First name: " + first_name + "\n");
				aReturn.append("Last name: " + last_name + "\n");

				return aReturn;
			};

			std::string first_name;
			std::string last_name;
		};

		// A data struct containing fields which may exist in the database.
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

			// For human readable printing purposes
			std::string get_string() const
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
		
		// This describes the data which can be stored in the database, containing mandatory and optional fields. 
		struct DatabaseEntry
		{
			// First name and last name are mandatory, but phone number is optional
			DatabaseEntry(const DatabaseEntryMandatoryFields& aDatabaseEntryMandatoryFields, 
						  const DatabaseEntryOptionalFields& aDatabaseEntryOptionalFields = DatabaseEntryOptionalFields())
				:	_mandatoryFields(aDatabaseEntryMandatoryFields),
					_optionalFields(aDatabaseEntryOptionalFields)
			{
			};

			// For human readable printing purposes
			std::string get_string() const
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