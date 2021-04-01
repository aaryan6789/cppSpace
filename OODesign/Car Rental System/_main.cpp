// --------------------------------------------------------------------------------------------------------------------
//                              CAR RENTAL SYSTEM

// A Car Rental System is a software built to handle the renting of automobiles for a short period of time, generally 
// ranging from a few hours to a few weeks. 
// A car rental system often has numerous local branches (to allow its user to return a vehicle to a different location)
// and primarily located near airports or busy city areas.

// Candidates should be able to discuss the following:
// 1> Identification: How will each vehicle be uniquely identified and located within the parking garage?
// 2> Fees          : How would the system collect a late fee for late returns?
// 3> Logs          : How would the system maintain a log for each vehicle and for each member?
// 4> Customization : How would the system handle members’ requests for additional services like roadside assistance, 
//                    insurance, and GPS

// --------------------------------------------------------------------------------------------------------------------

// SYSTEM ENUMS AND CONSTANTS
// VehicleType, VehicleStatus, AccountStatus, ReservationStatus ...

// SYSTEM ACTORS - People that interact with the System
// Member, Receptionist, Additional Driver

// SYSTEM SPECIFIC CLASSES - Top Level Classes specific to our Car Rental System
// CarRentalLocation, CarRentalSystem
// Vehicle, VehicleLog, VehicleReservation

// SYSTEM SEARCH Interface
// Vehicle Inventory, Search

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <ctime>

using namespace std;

// =====================================================================================================================
//                                              SYSTEM ENUMS AND CONSTANTS
// =====================================================================================================================
enum class BillItemType {
    BASE_CHARGE, ADDITIONAL_SERVICE, FINE, OTHER
};

enum class VehicleLogType {
    ACCIDENT, 
    FUELING, 
    CLEANING_SERVICE, 
    OIL_CHANGE, 
    REPAIR, 
    OTHER
};

enum class VanType {
    PASSENGER, CARGO
};

enum class CarType {
    ECONOMY, 
    COMPACT, 
    INTERMEDIATE, 
    STANDARD, 
    FULL_SIZE, 
    PREMIUM, 
    LUXURY
};

enum class VehicleStatus {
    AVAILABLE, 
    RESERVED, 
    RENTED, 
    LOST, 
    BEING_SERVICED, 
    OTHER
};

enum class ReservationStatus {
    ACTIVE, PENDING, CONFIRMED, COMPLETED, CANCELLED, NONE
};

enum class AccountStatus {
    ACTIVE, CLOSED, CANCELED, BLACKlistED, BLOCKED
};

enum class PaymentStatus {
    UNPAID, PENDING, COMPLETED, FILLED, DECLINED, CANCELLED, ABANDONED, SETTLING, SETTLED, REFUNDED
};

// Basic Structures for Address and Person Information
// Person has-a Address (Aggregation Design Pattern)

class Address {
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};

class Person {
    string name;
    Address address;
    string email;
    string phone;
};

// =====================================================================================================================
//                                              SYSTEM ACTORS
// These classes represent different people that interact with our system.
// We have four main Actors in our system:

// Receptionist : Mainly responsible for adding and modifying vehicles and workers. 
//                Receptionists can also reserve vehicles.
// Member       : All members can search the catalog, as well as reserve, pick-up, and return a vehicle.
// System       : Mainly responsible for sending notifications about overdue vehicles, canceled reservation, etc.
// Worker       : Mainly responsible for taking care of a returned vehicle and updating the vehicle log.
// =====================================================================================================================

// For simplicity, we are not defining getter and setter functions. The reader can
// assume that all class attributes are private and accessed through their respective
// public getter method and modified only through their public setter method.
class VehicleReservation;
class Account {
    string id;
    string password;
    AccountStatus status;
    Person person;

public:
    bool resetPassword();
};

class Member: public Account {
    int totalVehiclesReserved;

    list<VehicleReservation> getReservations();
};

class Receptionist: public Account {
    time_t dateJoined;

    list<Member> searchMember(string name);
};

class AdditionalDriver {
    string driverID;
    Person person;
};


// =====================================================================================================================
//                   SYSTEM SPECIFIC CLASSES - Top Level Classes specific to our Car Rental System

// The main classes of our Car Rental System:
// CarRentalSystem: The main part of the organization for which this software has been designed.

// CarRentalLocation: The car rental system will have multiple locations, each location will have attributes like 
//                    ‘Name’ to distinguish it from any other locations 
//                      and 
//                    ‘Address’ which defines the address of the rental location.

// Vehicle : The basic building block of the system. 
//           Vehicle will have a barcode, license plate number, passenger capacity, model, make, mileage, etc. 
//           Vehicles can be of multiple types, like car, truck, SUV, etc.

// Account: Mainly, we will have two types of accounts in the system, one will be a general member and 
//          the other will be a receptionist. 
//          Another account can be of the worker taking care of the returned vehicle.

// To encapsulate a vehicle, log, and reservation

// VehicleReservation : This class will be responsible for managing reservations for a vehicle i.e. processing the 
//                      reservation and return of a vehicle
// VehicleLog         : To keep track of all the events related to a vehicle.
// =====================================================================================================================

class CarRentalLocation {
    string name;
    Address location;

public:
    Address getLocation() {
        return location;
    };
};

class CarRentalSystem {
    string name;
    list<CarRentalLocation> locations;

public:
    bool addNewLocation(CarRentalLocation location);
};


class VehicleLog {
    string id;
    VehicleLogType type;
    string description;
    time_t creationDate;

    bool update();

    list<VehicleLogType> searchByLogType(VehicleLogType type);
};

class Vehicle {
    string licenseNumber;

    int passengerCapacity;
    string barcode;
    bool hasSunroof;
    VehicleStatus status;
    string model;
    string make;
    int manufacturingYear;
    int mileage;

    list<VehicleLog> log;

public:
    bool reserveVehicle();

    bool returnVehicle();
};

class Car: public Vehicle {
   CarType type;
};

class Van : public Vehicle {
   VanType type;
};

class Truck : public Vehicle {
   string type;
};

// We can have similar definition for other vehicle types
//...

class Notification {
    int id;
    time_t created_on;
    string content;

public:
    bool sendNotification();
};

// Declaring just for the sake of Declaration
class RentalInsurance;
class Equipment;
class Service;

class VehicleReservation {
    string reservationNumber;
    time_t creationDate;
    ReservationStatus status;
    time_t dueDate;
    time_t returnDate;
    string pickupLocationName;
    string returnLocationName;

    int customerID;
    Vehicle vehicle;
    // Bill bill;
    list<AdditionalDriver> additionalDrivers;
    list<Notification> notifications;
    list<RentalInsurance> insurances;
    list<Equipment> equipments;
    list<Service> services;

    VehicleReservation fetchReservationDetails(string reservationNumber);

    // list<Passenger> getAdditionalDrivers();
};


// VehicleInventory and Search: VehicleInventory will implement an interface ‘Search’ to facilitate the searching of vehicles:

class Search {
    virtual list<Vehicle> searchByType(string CarType) = 0;
    virtual list<Vehicle> searchByModel(string model) = 0;
};

class VehicleInventory: public Search {
    map<string, list<Vehicle>> vehicleTypes;
    map<string, list<Vehicle>> vehicleModels;
public:
    list<Vehicle> searchByType(string query) {
        // return all vehicles of the given type.
        return vehicleTypes[query];
    }

    list<Vehicle> searchByModel(string query) {
        // return all vehicles of the given model.
        return vehicleModels[query];
    }
};


int main() {
    cout << " CAR RENTAL SYSTEM" << endl;

    return 0;
}