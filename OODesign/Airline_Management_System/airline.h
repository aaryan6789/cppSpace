#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "enums.h"
#include "actors.h"

using namespace std;

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

#include <map>

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

        // API's

        // Search Flight - Different Variations
        vector<Flight> searchFlight(Airport src, Airport dst, time_t date);
        vector<Flight> searchFlight(Airport src);
        vector<Flight> searchFlight(Airport src, time_t date);

        void bookFlight(Customer& ct, Flight& flt) {
            cout << "Booking Flight" << endl;
            return;
        }

        bool cancelFlight(Flight flt);
};