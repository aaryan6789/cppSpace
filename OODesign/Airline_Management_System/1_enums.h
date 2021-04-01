#pragma once            // Very needed

#include <string>

using namespace std;

// This file containes the enums Constants for the Airline System Statuses

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