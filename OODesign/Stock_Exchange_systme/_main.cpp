#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// ====================================================================================================================
enum class ReturnStatus {
    SUCCESS, FAIL, INSUFFICIENT_FUNDS, INSUFFICIENT_QUANTITY, NO_STOCK_POSITION
};

enum class OrderStatus {
    OPEN, FILLED, PARTIALLY_FILLED, CANCELLED
};

enum class TimeEnforcementType {
    GOOD_TILL_CANCELLED, 
    FILL_OR_KILL, 
    IMMEDIATE_OR_CANCEL, 
    ON_THE_OPEN, 
    ON_THE_CLOSE
};

enum class AccountStatus {
    ACTIVE,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    None
};

class Location {
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string country;
};

class Constants {
    const int MONEY_TRANSFER_LIMIT = 100000;
};

// ====================================================================================================================

class OrderPart {
    double quantity;
    double price;
};

class Order {
    string orderId;
    bool isBuyOrder;
    OrderStatus status;
    TimeEnforcementType timeEnforcement;
    time_t creationTime;

    // Map for orderId and OrderPart to keep track of different orders from the same user
    map<int, OrderPart> parts;

public:
    Order(string& oId, bool ibo, OrderStatus& st, TimeEnforcementType& tft, time_t& ct){
        orderId = oId;
        isBuyOrder = ibo;
        status = st;
        timeEnforcement = tft;
        creationTime = ct;
    }

    void setStatus(OrderStatus& status){
        this->status = status;
    }

    bool saveInDB() {
        // save in the database
    }

    void addOrderParts(vector<OrderPart>& ord_parts) {
        for (OrderPart part : ord_parts) {
            parts[orderId] = part;
        }
    }
};


class LimitOrder: public Order {
    double priceLimit;

public:
    LimitOrder(string& oNum, bool ibo, OrderStatus& st, TimeEnforcementType& tft, time_t& ct, double& pLim){
        Order(oNum, ibo, st, tft, ct);
        priceLimit = pLim;
    }
};

// ====================================================================================================================
// For simplicity, we are not defining getter and setter functions. The reader can
// assume that all class attributes are private and accessed through their respective
// public getter methods and modified only through their public methods function.

// StockPosition: This class will contain all the stocks that the user holds.
class StockPosition {
    string symbol;
    double quantity;

public:
    double getQuantity() {
        return quantity;
    }
};

class Account {
    string id;
    string password;
    string name;
    AccountStatus status;
    Location address;
    string email;
    string phone;

public:
    bool resetPassword();
};

class Member: public Account {
    double availableFundsForTrading;
    time_t dateOfMembership;

    // This map will contain all the stocks that the user holds
    map<string, StockPosition> stockPositions;

    map<int, Order> activeOrders;

public:
    // Limit Order: Limit orders will allow a user to set a price at which they want to buy or sell a stock.
    int placeSellLimitOrder(string& stockId, float& quantity, int& limitPrice, TimeEnforcementType enforcementType){
        // check if member has this stock position
        if(stockPositions.find(stockId) == stockPositions.end()){
           return NO_STOCK_POSITION;
        }

        StockPosition stockPosition = stockPositions[stockId];
        // check if the member has enough quantity available to sell
        if(stockPosition.getQuantity() < quantity){
            return INSUFFICIENT_QUANTITY;
        }

        LimitOrder order(stockId, false, quantity, limitPrice, enforcementType);
        order.saveInDB();
        
        bool success = StockExchange::placeOrder(order);
        if(!success){
            order.setStatus(OrderStatus::FAILED);
            order.saveInDB();
        } 
        else {
            activeOrders.add(orderId, order);
        }
        
        return success;
    }

    int placeBuyLimitOrder(string stockId, float quantity, int limitPrice, TimeEnforcementType enforcementType){
        // check if the member has enough funds to buy this stock
        if(availableFundsForTrading < quantity * limitPrice ){
            return INSUFFICIENT_FUNDS;
        }

        LimitOrder order = new LimitOrder(stockId, quantity, limitPrice, enforcementType);
        order.isBuyOrder = true;
        order.saveInDB();
        bool success = StockExchange::placeOrder(order);
        if(!success){
            order.setStatus(OrderStatus::FAILED);
            order.saveInDB();
        } 
        else {
            activeOrders.add(orderId, order);
        }

        return success;
    }

    // this function will be invoked whenever there is an update from StockExchange against an order
    void callbackStockExchange(int orderId, vector<OrderPart> orderParts, OrderStatus status) {
        Order order = activeOrders[orderId];
        order.addOrderParts(orderParts);
        order.setStatus(status);
        order.updateInDB();

        if (status == OrderStatus::FILLED || status == OrderStatus::CANCELLEd) {
            activeOrders.remove(orderId);
        }
    }
};

int main() {
    return 0;
}