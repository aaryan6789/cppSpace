// Smart Pointer Implementation
// Requirements
// 1. Template implementation
// 2. Reference Count variable
//    The reference count variable is incremented when we add a new reference
//    to the object and decremented when the reference is removed.
#include <iostream>
using namespace std;
// SmartPtr class needs pointers to both the Object that it would be pointing to
// and to the refCount. These have to be the pointers rather than the actual
// object or the ref count value, as the goal of a smart pointer is that the
// reference count is tracked across multiple smart pointers to one object.
template <class T>
class smartPtr {
private:
    T* obj;
    unsigned* ref_count;

public:
    smartPtr(T* ptr){
        obj = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
    }




};

// 2 Constructors and Destructor
smartPtr(T * object){
    // Set the value of T* obj
    // Set the ref count to 1
}

// Contructor that will create a new Smart Pointer that points to an existing
// object. We will need to first set obj and ref count to pointer to sptr's obj
// and ref_count.
// Because we created a new reference to obj, we need to increment ref_count.
smartPtr(smartPtr<T>& sptr){

}

// Destructor
// We have to destroy a reference to the object.
// Decrement the ref_count. If ref_count is 0 then free the memory created by
// the integer and destroy the object
~smartPtr(smartPtr<T> sptr){
}


// There is one additional way that references can be created.
// By setting one smartPtr equal to another .
// So for this we would have to override the equal operator to handle this.




