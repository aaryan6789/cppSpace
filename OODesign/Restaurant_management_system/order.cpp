#include "constants.h"
#include "actors.h"
#include <vector>
#include <string>

using namespace std;

// class MealItem {
//   def __init__(self, id, quantity, menu_item):
//     self.__meal_item_id = id
//     self.__quantity = quantity
//     self.__menu_item = menu_item

//   def update_quantity(self, quantity):
//     None
// };

class MenuItem {
    private:
        int menuItemID;
        string title;
        string description;
        double price;

    public:
        bool updatePrice(double price);
};

class Meal {
    private:
        int meal_id;
        TableSeat seat;
        vector<MenuItem*> menu_items;

    public:
        Meal(int id, TableSeat st){
            this->meal_id = id;
            this->seat = st;
        }

        bool add_meal_item(Meal meal_item);
};

class Order {
    private:
        int order_id;
        OrderStatus status;
        time_t creation_time;

        vector<Meal*> meals;
        Table table;
        Waiter waiter;
        Chef chf;


    public:
        Order(int id, OrderStatus status, Table table, Waiter waiter, Chef chef){
            this->order_id = id;
            this->OrderStatus = status;
            this->creation_time = time(0);

            this->meals = {};
            this->table = table;
            this->waiter = waiter;
            this->chef = chef;
        }

        bool add_meal(Meal meal);

        bool remove_meal(Meal meal):

        bool get_status(){
            return this->status;
        }

        void set_status(self, status);
};