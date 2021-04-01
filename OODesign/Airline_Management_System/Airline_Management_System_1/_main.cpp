#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// ========================================================================================================
//                                      ENUMS & CONSTANTS

// This file containes the enums Constants for the Airline System Statuses
// ========================================================================================================

// Flight Status
 
enum class FlightStatus{
	ACTIVE,
	SCHEDULED,
	DELAYED,
	DEPARTED,
	LANDED,
	IN_AIR,
	ARRIVED,
	CANCELLED,
	DIVERTED,
	UNKNOWN
};

enum class PaymentStatus{
	UNPAID,
	PENDING,
	COMPLETED,
	FILLED,
	DECLINED,
	CANCELLED,
	ABANDONED,
	SETTLING,
	SETTLED,
	REFUNDED
};

enum class ReservationStatus{
	REQUESTED,
	PENDING,
	CONFIRMED,
	CHECKED_IN,
	CANCELLED,
	ABANDONED
};

enum class SeatClass {
	ECONOMY,
	ECONOMY_PLUS,
	PREFERRED_ECONOMY,
	BUSINESS,
	FIRST_CLASS
};

enum class SeatType {
	REGULAR,
	ACCESSIBLE,
	EMERGENCY_EXIT,
	EXTRA_LEG_ROOM
};

enum class AccountStatus{
	ACTIVE,
	CLOSED,
	CANCELED,
	BLACKLISTED,
	BLOCKED
};

class Address {
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};


// ========================================================================================================
//                                              ACTORS
//
// This section contains the various Actors for the System.
// We already scoped out the Identities and their respective functions.
// ========================================================================================================

class Account {
    int id;
    string password;
    AccountStatus status;

    public:
        Account() {}

        bool resetPassword(string new_pass);
};


// This is a Base class from which the Other Actors will Inherit
class Person {
    private:
        string name;
        string address;
        string email;
        string phone;

        // Each person would have an account
        Account acc;        // Composition Design Pattern
    
    public:
        Person() {}

        Person(string name, string add, string em, string ph){
            this->name = name;
            this->address = add;
            this->email = em;
            this->phone = ph;
        }

        void details(){
            cout << "Person Details" << endl;
            cout << name << endl;
            cout << address << endl;
            cout << email << endl;
            cout << phone << endl;
            
        }
};


class Customer : public Person {
    private:
        string frequent_flyer_no;
        string cust_id;

    public:
        Customer() {}

        Customer(string name, string add, string em, string ph, string ffn, string cst_id): Person(name, add, em, ph) {
            this->frequent_flyer_no = ffn;
            this->cust_id = cst_id;
        }

        // API's


        void details(){
            Person::details();
            cout << frequent_flyer_no << endl;
            cout << cust_id << endl;
        }
};

// ========================================================================================================
//                                  AIRLINE SYSTEM                          
// ========================================================================================================

class Airport {
    private:
        string name;
        string address;
        string code;

    public:
        Airport() {}

        Airport(string nm, string add, string code){
            this->name = nm;
            this->address = add;
            this->code = code;
        }

        // Get a List of Flight Numbers flying from the Airport
        vector<string> getFlights();

};

// Airport Contains Flights
// So lets make a Class to keep Flights Info
class Flight {
    private:
        string flightNumber;
        Airport src;
        Airport dest;
        int durationOfFlight;   // In Mins
        FlightStatus status;
        int maxCapacity;
    
    public:
        Flight() {}

        Flight(string fn, Airport src, Airport dst, int dof, FlightStatus st, int cap){
            this->flightNumber = fn;
            this->src = src;
            this->dest = dst;
            this->durationOfFlight = dof;
            this->status = st;
            this->maxCapacity = cap;
        }

        bool cancel();

        void addFlightSchedule();

        void print(){
            cout << "Flight Details : " << this->flightNumber << this->maxCapacity << endl;
        }
};

class FlightSeat {
    string seatNum;
    SeatType stType;
    SeatClass stCls;
    double seatFare;

    public:
        double getFare();
};



class FlightReservation {
    string resNum;
    Flight flt;
    time_t creation_time;
    ReservationStatus status;

    // Map of Customer Id and its Flight Seat
    map<int, FlightSeat> seatMap;

    public:
        FlightReservation getReservationDetails(int reservation_num);
};


// There would be an iteinerary for each customer
class Itinerary {
    string customer_id;
    Airport src;
    Airport dest;
    time_t createDate;
    vector<FlightReservation> reservations;

    public:
        vector<FlightReservation> getReservations(string cust_id);
};

class AirlineSystem {  
    string name;
    string code;
    // Keep a Map of Flight Number and Flight Info
    map<string, Flight> allflightsOfAirline;
    map<string, vector<Flight>> flightsFromAirport;
    map<time_t, vector<Flight>> flightsOnTheDay;

    public:
        AirlineSystem(string name, string code){
            this->name = name;
            this->code = code;
        }

        vector<Flight> searchFlight(Airport src, Airport dst, time_t date);
        vector<Flight> searchFlight(Airport src);
        vector<Flight> searchFlight(Airport src, time_t date);

        bool bookFlight(Customer& ct, Flight& flt) {
            cout << "Booking Flight" << endl;
            return;
        }

        bool cancelFlight(Flight flt);
        
};

int main() {

    AirlineSystem as("Alaska", "AA");
    Customer c1("Harsh", "San Mateo", "haha@gmail", "909090", "FFNO", "NEW10");
    c1.details();

    Airport a1("SFO", "San Francisco", "SFO");
    Airport a2("SJC", "San Jose", "SJC");

    Flight f1("AA3400", a1, a2, 30, FlightStatus::SCHEDULED, 30);
    f1.print();

    as.bookFlight(c1, f1);


    return 0;
}