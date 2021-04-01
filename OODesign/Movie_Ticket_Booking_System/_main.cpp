#include <iostream>
#include <string>
#include <list>
#include <memory>

using namespace std;

// =======================================================================================================
//                                  ENUMS and CONSTANTS
// This section keeps all the Enums and Constants that might be needed in the Movie Ticket bookeing System.
// =======================================================================================================

// Status for the Booking Request
enum class BookingStatus {
    REQUESTED,
    PENDING,
    CONFIRMED,
    CHECKED_IN,
    CANCELED,
    ABANDONED
};

// Cinema Hall Seat Type. Could be used for different prices.
enum class SeatType {
    REGULAR, 
    PREMIUM, 
    ACCESSIBLE, 
    SHIPPED, 
    EMERGENCY_EXIT, 
    OTHER
};

// Each Customer has to have a account for Booking the Ticket.
// So we need a account Status enum to keep track of their account status.
enum class AccountStatus {
    ACTIVE, BLOCKED, BANNED, COMPROMISED, ARCHIVED, UNKNOWN
};

enum class PaymentStatus {
    UNPAID, PENDING, COMPLETED, FILLED, DECLINED, CANCELLED, ABANDONED, SETTLING, SETTLED, REFUNDED
};

// Constant Address Class to keep address of Customer or Cinema Hall.
class Address {
public:
	string streetAddress;
	string city;
	string state;
	string zipCode;
	string country;
};


// =======================================================================================================
//                                  ACTORS of Movie Ticket Booking System
// 1. Admin
// 2. Customer
// 3. Guest
// 4. Front Desk Officer
// 5. System

// For simplicity, we are not defining getter and setter functions. The reader can
// assume that all class attributes are private and accessed through their respective
// public getter method and modified only through their public setter method.
// =======================================================================================================

// Account Information for each Actor interacting with the system
class Account {
private:
    int id;
    string passwd;
    AccountStatus status;

public:
    Account() {}

    bool resetPassword(string new_pass);
};

// Base Class Person for various Actors to Reuse Code.
class Person {
private:
    string name;
    Address adrs;
    string email;
    string phone;

    Account acc;        // Each Person has-a account. (Composition Design Pattern)
public:
    Person() {}

    Person(string& nm, Address& ad, string& em, string& ph, Account& act): 
                                    name(nm), adrs(ad), email(em), phone(ph), acc(act) {}

    void details(){
        cout << "Person Details" << endl;
        cout << name << endl;
        cout << adrs.zipCode << endl;
        cout << email << endl;
        cout << phone << endl;
    }
};


// =======================================================================================================
//                                  Classes of Movie Ticket Booking System
// 1. City, Cinema, CinemaHall
// 2. Show, Movie
// 3. 
// ====================================================================================================== =

// City: Each city can have multiple cinemas.
class City {
    string name;
    string state;
    string zipCode;
};

// CinemaHall: Each cinema will have multiple halls containing multiple seats.
class CinemaHall {
    string name;
    int totalSeats;

    // list<CinemaHallSeat> seats;
    // list<Show> shows;
};

// Cinema: 
// The main part of the organization for which this software has been designed. e.g. AMC, RegalCinemas, Drive In
// It has attributes like ‘name’ to distinguish it from other cinemas.
class Cinema {
    string name;
    int totalCinemaHalls;

    list<CinemaHall> halls;
};

// =======================================================================================================
//                              SHOW and MOVIE Structures

// Movie: The main entity of the system. 
//        Movies have attributes like title, description, language, genre, release date, city name, etc.
//        A movie will have many shows.
// Show: Each movie can have many shows; each show will be played in a cinema hall.
// =======================================================================================================
#include <ctime>

// Since Show and Movie have a circular dependency, we're going to forward declare Show
class Show;

class Movie {
    string title;
    string description; 
    int durationInMins;
    string language;
    
    time_t releaseDate;
    string country;
    string genre;

    list<Show> shows;

public:
    Movie() {};

    // API's
    list<Show> getShows(){
        return shows;
    }
};

class Show {
    int showID;

    time_t startTime;
    time_t endTime;

    // Show has a CinemaHall
    CinemaHall playedAt;
    Movie mov;
};

class Booking;

// Customer is a Person who can View Movie Schedule, Book a Ticket or Cancel.
class Customer: public Person {
private:
    string member_id;

public:
    Customer() {}

    Customer(string& name, Address& add, string& em, string& ph, Account& act, string& mem_id): Person(name, add, em, ph, act) {
        this->member_id = mem_id;
    }

    // API's
    void details(){
        Person::details();
        cout << member_id << endl;
    }

    // Interacting API's
    // Make a Booking (Booking is a Class that will hold the Booking Information)
    bool makeBooking(Booking& booking);

    // Return all the bookings of the Customer
    list<Booking> getBookings();
};

class Admin: public Person {
    string admin_id;

public:
    Admin() {}

    Admin(string& name, Address& add, string& em, string& ph, Account& act, string& a_id): Person(name, add, em, ph, act) {
        this->admin_id = a_id;
    }

    // API's
    bool addMovie(Movie mv);
    bool addShow(Show sh);
    bool blockUser(Customer cust);
};

// CinemaHall Seat is going to be inherited by ShowSeat
class CinemaHallSeat {};    // Not Forward Declation

class Payment {
    double amount;
    time_t createdOn;
    int transactionId;
    PaymentStatus status;
};

class ShowSeat: public CinemaHallSeat {
    int showSeatId;
    bool isReserved;
    double price;
};

class Booking {
    string bookingNumber;
    int numberOfSeats;
    time_t createdOn;
    BookingStatus status;

    Show show;
    list<ShowSeat> seats;
    Payment payment;

    bool makePayment(Payment payment);
    bool cancel();
    bool assignSeats(list<ShowSeat> seats);
};


#include <map>

// Search interface and Catalog: 
// Catalog will implement Search to facilitate searching of products.

// C++ has no built-in concepts of interfaces. 
// You can implement it using abstract classes which contains only pure virtual functions. 
// C++ allows multiple inheritance, you can inherit this class to create another class which will then contain
// this interface in it.

class Search {
    virtual list<Movie> searchByTitle(string title) = 0;
    virtual list<Movie> searchByLanguage(string language) = 0;
    virtual list<Movie> searchByGenre(string genre) = 0;
    virtual list<Movie> searchByReleaseDate(time_t relDate) = 0;
    virtual list<Movie> searchByCity(string cityName) = 0;
};


class Catalog : public Search {
    map<string, list<Movie>> movieTitles;
    map<string, list<Movie>> movieLanguages;
    map<string, list<Movie>> movieGenres;
    map<time_t, list<Movie>> movieReleaseDates;
    map<string, list<Movie>> movieCities;

    list<Movie> searchByTitle(string title) {
        return movieTitles[title] ;
    }

    list<Movie> searchByLanguage(string language) {
        return movieLanguages[language];
    }


    list<Movie> searchByCity(string cityName) {
        return movieCities[cityName];
    }
};


int main() {
    cout << " Movie Ticket Booking System " << endl;
    return 0;
}




















