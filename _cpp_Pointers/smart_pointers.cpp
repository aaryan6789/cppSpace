#include "_pointers.h"
#include <memory>



class Entity{
    public:
        int x;
        int y = 0;

    public:
        Entity(): x(0), y(1){}
        ~Entity(){}

};

using namespace std;

void smart_pointers(){

    unique_ptr<Entity> e(new Entity());     // Explicit constructor call


}