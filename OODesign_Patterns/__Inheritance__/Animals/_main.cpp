#include <iostream>
using namespace std;

// Write classes code here

class Animal {
  private:
    string name;
    string sound;

  public:
    Animal() {
      name = "";
      sound = "";
    }

    Animal(string nm, string sd) {
      name = nm;
      sound = sd;
    }

    void Animal_Details() {
      cout << name << endl;
      cout << sound << endl;
    }
};

class Dogs : public Animal {
  private:
    string family;

  public:
    Dogs(string nm, string sd, string fm) : Animal(nm, sd) {
      family = fm;
    }

    Dogs(string nm, string sd) : Animal(nm, sd) {
      family = "carnivores";
    }

    void Dog_detail() {
      Animal_Details();
      cout << family << endl;
    }
};

class Sheeps : public Animal {
  private:
    string color;

  public:
    Sheeps(string nm, string sd, string col) : Animal(nm, sd) {
      color = col;
    }

    Sheeps(string nm, string sd) : Animal(nm, sd) {
      color = "White";
    }

    void Sheep_detail() {
      Animal_Details();
      cout << color << endl;
    }
};

int main() {
  // Make classes objects here
  Dogs d("Pongo", "Woof Woof");
  d.Dog_detail();
  Sheeps s("Billy", "Baaa Baaa");
  s.Sheep_detail();
}