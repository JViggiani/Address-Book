# Address Book

This is the implementation of the technical assessment required by Foundry.

Minimum requirements:

- Provide your solution as a public GitHub repository link 
- Support from zero to a “large number” of entries. 
- Entries should contain: 
  - A first and last name. 
  - An optional phone number. 
- Provide functionality to: 
  - Add an entry. 
  - Remove an entry. 
  - Retrieve entries in alphabetical order, sorted by first name. 
  - Retrieve entries in alphabetical order, sorted by last name. 
  - Retrieve entries whose first or last name exactly or partially match a supplied search string, from the beginning of the name (e.g. searching for “Dan” would match any entries with “Daniel” as well as any “Dan”). 
  - Make this matching case insensitive. 
- Provide instructions on how to build and run your application. 

To change the ordering of fetching entries, enter the Read menu and select 1 to view order settings and 2 to change it. 

The search string by default is a regex string encoded with ECMAScript. For example, searching ".*" will retrieve all documents. 

## Building and Executing

This project was built in Visual Studio 2019 and is intended to be cloned, built and run inside of VS2019. 

After cloning inside VS2019, you will need to install boost with NuGet: 

https://docs.microsoft.com/en-us/nuget/consume-packages/install-use-packages-visual-studio 

Use NuGet, and search for and install: "boost-vc142 v1.72" inside NuGet. 

## Future Requirements

- It would be good to adhere to standard CRUD database actions. An update menu section was added but was not implemented. Ideally the user could define the key to update the entry of, and the database item could be edited without having to perform a delete and then an add. 
- Originally it was sought that this program would have a GUI, however the QT account registration service seemed to be down, so the editor could not be used. A console application was completed instead. 
- The entire database is loaded into memory at the same time, which is not memory efficient. Instead, the Database class should be used to maintain a connection to an SQL database, and the rest of the program should act as an interface to it. 
- The database singleton design should be revamped, as it's hard to mock a database connection. SQL databases often support multiple connections, so a better way to implement this would be to have a singleton maintain a pool of database connections represented by a queue. The pool itself would have no business logic, so would never need to be mocked. It would simply contain connection instances, which could be mocked. 
- There should be a cleaner separation between classes which perform UI duties, classes whose duty is to update the database, and classes which contain business logic. 
- Unit tests should be created after the database singleton is removed. 

Time taken: approx 6 hours. 
