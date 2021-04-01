#include <iostream>

using namespace std;

class Vehicle {
    // Private Data Members
    string speed;
    string model;

    public:
    
    Vehicle() { // Default Constructor
        speed = "100";
        model = "Tesla";
    }

    // Getter Function
    string getSpeed() {
        return speed;
    }

    // Getter Function
    string getModel() {
        return model; 
    }
};

// Derived Class
    class Car : public Vehicle {
    
    string name; //  Name of a Car
    
    public:
    Car() { // Default Constructor
        name = "";
    }

    // This function sets the name of the car
    void setDetails(string name) { // Setter Function
        this->name = name;
    }

    // This function calls the Base class functions and appends the result with the input 
    string getDetails(string carName) {
        string details = carName + ", " + getModel() + ", " + getSpeed(); // calling Base Class Function
        return details;
    } 
};

int main() {
    Car * car = new Car();
    string details = car->getDetails("RoadSter");
    cout << "Car details: " << details << endl;
    delete car;
}