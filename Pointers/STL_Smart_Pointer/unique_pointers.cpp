#include "_pointers.h"
#include <memory>

using namespace std;

class Entity{
    public:
        int x;
        int y = 0;
    public:
        Entity(): x(0), y(1){}
        ~Entity(){}
};

void smart_pointers(){
    unique_ptr<Entity> e(new Entity());     // Explicit constructor call
}


class One{
    int x{1};
    double y{2.3};

    public:
        void show(){
            cout << "One::show() " << x << " " << y << endl;
        }
};

unique_ptr<One> getOne(){
    unique_ptr<One> res (new One);

    res->show();
    cout << " res " << res.get() << endl;

    return res;
}

void unique_pointer(){
    cout << "\n======\nUnique Pointer \n======" << endl;
    // Declare a Unique Pointer
    unique_ptr<int> val (new int(15));
    cout << "Unique Pointer Address (val) = " << &val << endl;
    cout << "Unique Pointer Value (*val)  = " << *val << endl;

    int x = 45;
    int* ptrX = &x;
    cout << "\nx = " << x << "\nptrX value (*ptrX) = " << *ptrX << endl;

    unique_ptr<int> val2 (new int(22));
    cout << "Unique Pointer Address (val2) = " << &val2 << endl;
    cout << "Unique Pointer Value (*val2)  = " << *val2 << endl;

    // unique_ptr<int> val3 (ptrX);
    // cout << "Unique Pointer Address (val3) = " << val3 << endl;
    // cout << "Unique Pointer Value (*val3)  = " << *val3 << endl;

    cout << "\n Moveing val2 into val4" << endl;
    unique_ptr<int> val4 = move(val2);
    // unique_ptr<int> val4 = val2;         // Compiler Error that Copy Contructor is Deleted
    cout << "Unique Pointer Address (val4) = " << &val4 << endl;
    cout << "Unique Pointer Value (*val4)  = " << *val4 << endl;


    // GeeksForGeeks

    unique_ptr<int> A (new int(10));
    cout << "A Address = " << A.get() << endl;
    // A.release();

    unique_ptr<int> B = move(A);
    cout << "A Address = " << A.get() << endl;
    cout << "B Address = " << B.get() << endl;

    unique_ptr<int> C = move(B);
    cout << "A Address = " << A.get() << endl;
    cout << "B Address = " << B.get() << endl;
    cout << "C Address = " << C.get() << endl;

    unique_ptr<One> res = getOne();
    cout << res.get() << endl;
}

void customizeA(unique_ptr<One> ptr){

    cout << "Ptr get " << ptr.get() << endl;;

}

void passing_unique_pointers(){

    unique_ptr<One> A = make_unique<One>();
    cout << A.get() << endl;

    customizeA(move(A));
}
