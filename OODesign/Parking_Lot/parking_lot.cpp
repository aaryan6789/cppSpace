#include <iostream>
#include <vector>

using namespace std;

/* 
PARKING LOT OO Design
================================================================================
Constraints and assumptions
1. What types of vehicles should we support?
- Motorcycle, Car, Bus

2. Does each vehicle type take up a different amount of parking spots?
- Yes
- Motorcycle spot -> Motorcycle
- Compact spot -> Motorcycle, Car
- Large spot -> Motorcycle, Car
- Bus can park if we have 5 consecutive "large" spots

3. Does the parking lot have multiple levels?
- Yes
*/

// Enum for Vehicle Size
enum VehicleSize {
    MotorCycle = 0,
    Compact = 1,
    Large = 2 
};

// Forware Declarations of Some classes needed
class Vehicle;

// Representation of a Level in a Parking Lot
class Level {
    int id;                     // Level Number
    int num_rows;               // Number of Rows in the Level
    int spots;                  // Number of Spots in the level
};

// Representation of a Spot in a Level in a Parking Lot
class Spot {
public:
    int level_id;               // Level Id of the spot
    int row_id;                 // Row id of the spot
    int spot_number;            // Spot Number
    VehicleSize spot_size;      // Size of the Spot

    VehicleSize vh_size;        // Size of the Vehicle currently in the spot
    Vehicle* vh;                // Vehicle the Spot currently holds

public:     // Member Functions for Spot
    // Constructor for Spot
    Spot(int lv_id, int rw_id, int spt_num, VehicleSize spt_sz){
        this->level_id  = lv_id;
        this->row_id    = rw_id;
        this->spot_number   = spt_num;
        this->spot_size = spt_sz;
    }

    // If the Spot is currenlty availble or not.
    // If there is a vehicle in the spot then its not available else it is available
    bool is_available(){
        if(this->vh != NULL)
            return true;
        
        return false;
    }

    bool can_fit_vehcile(Vehicle* v){
        if(!v)
            return false;
        
        return true;
    }

    void park_vehicle(Vehicle* v){}

    void remove_vehicle(Vehicle* v){}
};

// Base Class For representing any vehicle
class Vehicle {
protected:      // or Public just not private
    VehicleSize v_size;                     // Size of the Vehicle
    string license_plate;                   // License Plate
    VehicleSize spot_size;                  // What type of spot can it take
    vector<Spot> spots_taken;               // Spots taken

public:
    // Constructor
    Vehicle(VehicleSize vhs, string lic, VehicleSize sps) {
        this->v_size = vhs;
        this->license_plate = lic;
        this->spot_size = sps;
    }

    // Clear Spots when a Vehicle Leaves from the Parkign Lot
    void clear_spots(){
        for (auto& sp: spots_taken){
            sp.remove_vehicle(this);
        }

        spots_taken.clear();
    }

    void take_spot(Spot& sp){
        spots_taken.push_back(sp);
    }

    virtual bool can_fit_in_spot(Spot sp) = 0;

};

class MotorCycle : public Vehicle {

};

class Car : public Vehicle {
public:
    // Constructor (Parameterized + Inheritanced)
    Car(VehicleSize vhs, string lic, VehicleSize sps) : Vehicle(vhs, lic, sps) {
        v_size = vhs;
        license_plate = lic;
        spot_size = sps;
    }

    bool can_fit_in_spot(Spot sp) override {
        if(sp.spot_size == Large || sp.spot_size == Compact){
            return true;
        }

        return false;
    }

};

class Bus : public Vehicle {

};

class ParkingLot {
    int num_levels;
    int total_spots;

public:
    ParkingLot(int levs, int tspts) {
        num_levels = levs;
        total_spots = tspts;
    }

    bool park_vehicle(Vehicle* v){
        return false;
    }
};


int main(){
    cout << "Parking Lot OOD Design" << endl;
    // Create Some Vehicles 
    Vehicle* car = new Car(Compact, "8CBW255", Compact);


    // Create a Parkign Lot
    ParkingLot plot(2, 100);

    // Create Some Levels in a Parking Lot

    return 0;
}