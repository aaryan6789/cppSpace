#include "_pointers.h"
#include <memory>
using namespace std;

void shared_pointer(){
    shared_ptr<int> p1 (new int(12));

    cout << "p1 Address = " << p1.get() << endl;
    cout << "p1 Value   = " << *p1 << endl;
    cout << "p1 References = " << p1.use_count() << endl;

    shared_ptr<int> p2 (p1);
    cout << "p2 Address = " << p2.get() << endl;
    cout << "p2 Value   = " << *p2 << endl;
    cout << "p2 References = " << p2.use_count() << " p1 References = " << p1.use_count() << endl;

    shared_ptr<int> p3 (p1);
    cout << "p3 Address = " << p3.get() << endl;
    cout << "p3 Value   = " << *p3 << endl;
    cout << "p3 References = " << p3.use_count() << " p2 References = " << p2.use_count() << " p1 References = " << p1.use_count() << endl;

    p1.reset();
    p2.reset();

    cout << "p3 Address = " << p3.get() << endl;
    cout << "p3 Value   = " << *p3 << endl;
    cout << "p3 References = " << p3.use_count() << " p2 References = " << p2.use_count() << " p1 References = " << p1.use_count() << endl;

}

/**
shared_ptr<A> <----| shared_ptr<B> <------
    ^              |          ^          |
    |              |          |          |
    |              |          |          |
    |              |          |          |
    |              |          |          |
class A            |     class B         |
    |              |          |          |
    |              ------------          |
    |                                    |
    -------------------------------------

If we make the shared_ptr of the class B and A,
the use_count of the both pointer is 2.

When the shared_ptr goes out od scope the count still remains 1 and hence
the A and B object does not gets deleted.
 */

void cyclic_dependency(){
    cout << "\nShared pointer : CYCLIC DEPENDENCY " << endl;
    class B;
    class A {
        // shared_ptr<B> sP1; // use weak_ptr instead to avoid CD
        weak_ptr<B> sP1; // use weak_ptr instead to avoid CD

    public:
        A() {
            cout << "A()" << endl;
        }

        ~A() {
            cout << "~A()" << endl;
        }

        void setShared(shared_ptr<B>& p) {
            sP1 = p;
        }
    };

    class B {
        // shared_ptr<A> sP1;
        weak_ptr<A> sP1;

    public:
        B() {  cout << "B()" << endl; }
        ~B() { cout << "~B()" << endl; }

        void setShared(shared_ptr<A>& p) {
            sP1 = p;
        }
    };

    shared_ptr<A> aPtr(new A);
    shared_ptr<B> bPtr(new B);

    aPtr->setShared(bPtr);
    bPtr->setShared(aPtr);
}

/*
As we can see from the output that A and B pointer are never deleted and 
hence memory leak.
To avoid such issue just use weak_ptr in class A instead of shared_ptr which 
makes more sense.
*/