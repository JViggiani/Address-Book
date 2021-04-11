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

			std::string first_name;
			std::string last_name;
		};

		struct DatabaseEntryOptionalFields
		{
			DatabaseEntryOptionalFields() = default;
			
			void operator=(const Menu::Data::AddressBookOptionalMenuResults& aAddressBookOptionalMenuResults)
			{
				phone_number = aAddressBookOptionalMenuResults.phone_number;
			};
			
			
			DatabaseEntryOptionalFields(const Menu::Data::AddressBookOptionalMenuResults& aAddressBookOptionalMenuResults) 
				: phone_number(aAddressBookOptionalMenuResults.phone_number)
			{
			};

			std::string phone_number;
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
			
			DatabaseEntryMandatoryFields _mandatoryFields;
			DatabaseEntryOptionalFields _optionalFields;
		};
	}
}