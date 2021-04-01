#include "constants.h"

using namespace std;

int main() {

    ReservationStatus::CANCELED;
    // We have to cast a Enum value to a particular data type for printing its value
    cout <<  int(ReservationStatus::CANCELED) << endl;

    
    return 0;
}