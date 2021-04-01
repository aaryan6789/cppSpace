#pragma once
#include <iostream>
#include <string>

using namespace std;

enum class ReservationStatus {
    REQUESTED = 1, 
    PENDING, 
    CONFIRMED, 
    CHECKED_IN, 
    CANCELED, 
    ABANDONED
};

enum class SeatType {
    REGULAR = 1,
    KID, 
    ACCESSIBLE, 
    OTHER
};

enum class OrderStatus {
    RECEIVED = 1,
    PREPARING,
    COMPLETED,
    CANCELLED,
    NONE
};

enum class TableStatus {
    FREE = 1, RESERVED, OCCUPIED, OTHER
};

enum class AccountStatus {
    ACTIVE, CLOSED, CANCELED, BLACKLISTED, BLOCKED
};

enum class PaymentStatus {
    UNPAID, PENDING, COMPLETED, FILLED, DECLINED, CANCELLED, ABANDONED, SETTLING, SETTLED, REFUNDED
};


class Address {
    private:
        string street_address;
        string city;
        string state;
        int zip_code;
        string country;

    public:
        Address(string street, string city, string state, int zip_code, string country) {
            this->street_address = street;
            this->city = city;
            this->state = state;
            this->zip_code = zip_code;
            this->country = country;
        }
};