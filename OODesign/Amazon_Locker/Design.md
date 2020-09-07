The answer would be really straight forward, and the design should be like this:

# Object 
## Dimensions 
(this can be even an interface and implemented on the lower levels if the solution language support this)
contains the following

##  Fields: 
    int height, 
    int width and 
    int depth
## Methods: 
>>  boolean fitIn(Dimensions), 
>>  int getVolume()

# Object Package 
contains the following:
## Fields: 
    Dimensions dimensions, 
    Int volume and 
    some other fields for example source address and target address etc.

## Methods: for example delivered and some getters and setters where needed

Object one: Locker and it contains the following
Fields: Dimensions, int volume boolean empty, string ID
Methods: boolean isEmpty() , putPackage(package), Package removePackage() etc..

now this is tricky as if you have a collection of Lockers it would take a long time to compare which container to use which is not good, so it is better to reference them by demotion and volume or any other solution to minimise search time. but this is out of the topic of the question.

# ========
# Use cases

Put a package into a locker
Get a package from a locker
Find a locker space for a package and reserve it
Track if a package in locker or not
Shipping status?
Expiration for a package in a locker?
Access control - normal user cannot do admin works?
History?
Multiple packages in one slot?

## Classes
Locker
fields:

    Slots - [slots]
    location
    Map - code to slot
    Locker ID
    methods
    Reserve - lock a slot for a package to come in
    Private - Open - open a slot
    Lookup - find available slots for certain package size
    Put - put a package in
    Retrieve - get a package out
    checkExpired - check all expired slots
    Private - isAdmin - check if the current user is an admin
    Close - close a slot - serves as a confirmation for operations
    Private - Generate code

Package
Fields:

    Id
    size - enum?
    Status - preparing, shipped, arrived, received, returned?
    Locker id
    Slot id
    Locker code
    Method:
    Update status
    Update locker info

Slot
Fields:

    Size
    Id
    Expiration date
    packageID
    Method:
    Put - put a package in
    Get - get a package out