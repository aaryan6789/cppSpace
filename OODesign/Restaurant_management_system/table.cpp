#include <vector>
#include "constants.h"


class Table {
    private:
        int table_id;
        int max_capacity;
        int location_identifier;
        TableStatus status = TableStatus::FREE;
        vector<SeatType> seats;

    public:
        Table() {}
        
        Table(int id, int max_capacity, int location_identifier, TableStatus status) {
            this->table_id = id;
            this->max_capacity = max_capacity;
            this->location_identifier = location_identifier;
            this->status = status;
            this->seats = {};
        }

        bool is_table_free();

        bool add_reservation();
        
        bool search(int capacity, time_t start_time) {
            // return all tables with the given capacity and availability
        }
};

class TableSeat {
    private:
        int table_seat_number = 0;
        SeatType type = SeatType::REGULAR;

    public:
        TableSeat(int sn, SeatType typ) {
            this->table_seat_number = sn;
            this->type = typ;
        }
    

        void update_seat_type(SeatType seat_type);
};


class Reservation {
    private:
        int reservation_id;
        time_t time_of_reservation;
        int people_count = 0;
        ReservationStatus status;
        string notes;
        time_t checkin_time;
        int cstmr;  // TODO: Embed Customer Class
        vector<Table> tables = {};

    public:
        Reservation(int id, int people_count, string notes, int customer){
            this->reservation_id = id;
            this->time_of_reservation = time(0);
            this->people_count = people_count;
            this->status = ReservationStatus::REQUESTED;
            this->notes = notes;
            this->cstmr = customer;
            this->tables = {};
        }

        void update_people_count(int count) {}

};