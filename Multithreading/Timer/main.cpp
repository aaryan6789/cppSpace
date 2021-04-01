#include <iostream>
using namespace std;

// 64 bit timer
int timer(){

    unsigned int high = 0;
    unsigned int low = 0;

    for (;;) {
        while(high != 0xF)
            high++;
        while(high == 0xF && low != 0xF){
            low += 1;
        }

        cout << "High" << high << endl;
        cout << "Low " << low << endl;
    }
}

int main() {
    timer();
}