#include "enums.h"
#include "actors.h"
#include "airline.h"

#include <map>

using namespace std;



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