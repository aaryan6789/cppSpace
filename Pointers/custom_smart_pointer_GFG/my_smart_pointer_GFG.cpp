#include <iostream>
using namespace std;
/**
 * Shared Pointers:
 * A std::shared_ptr is a container for raw pointers.
 * It is a reference counting ownership model i.e. it maintains the reference count
 * of its contained pointer in cooperation with all copies of the std::shared_ptr.
 * So, the counter is incremented each time a new pointer points to the resource
 * and decremented when destructor of the object is called.
 *
 * Reference Counting :
 * It is a technique of storing the number of references, pointers or handles to a
 * resource such as an object, block of memory, disk space or other resources.
 *
 * An object referenced by the contained raw pointer will not be destroyed until
 * reference count is greater than zero i.e. until all copies of std::shared_ptr
 * have been deleted.
 *
 * When to use:
 * We should use shared_ptr when we want to assign one raw pointer to multiple owners.
 */

// Class representing a reference counter class
class Counter {
public:
	// Constructor
	Counter()
		: m_counter(0){};

	Counter(const Counter&) = delete;
	Counter& operator=(const Counter&) = delete;

	// Destructor
	~Counter()
	{
	}

	void reset()
	{
		m_counter = 0;
	}

	unsigned int get()
	{
		return m_counter;
	}

	// Overload post/pre increment
	void operator++()
	{
		m_counter++;
	}

	void operator++(int)
	{
		m_counter++;
	}

	// Overload post/pre decrement
	void operator--()
	{
		m_counter--;
	}
	void operator--(int)
	{
		m_counter--;
	}

	// Overloading << operator
	friend ostream& operator<<(ostream& os, const Counter& counter)
	{
		os << "Counter Value : "
		<< counter.m_counter << endl;
	}

private:
	unsigned int m_counter{};
};

// Class representing a shared pointer
template <typename T>

class Shared_ptr {
public:
	// Constructor
	explicit Shared_ptr(T* ptr = nullptr)
	{
		m_ptr = ptr;
		m_counter = new Counter();
		if (ptr) {
			(*m_counter)++;
		}
	}

	// Copy constructor
	Shared_ptr(Shared_ptr<T>& sp)
	{
		m_ptr = sp.m_ptr;
		m_counter = sp.m_counter;
		(*m_counter)++;
	}

	// Reference count
	unsigned int use_count()
	{
		return m_counter->get();
	}

	// Get the pointer
	T* get()
	{
		return m_ptr;
	}

	// Destructor
	~Shared_ptr()
	{
		(*m_counter)--;
		if (m_counter->get() == 0) {
			delete m_counter;
			delete m_ptr;
		}
	}

	friend ostream& operator<<(ostream& os, Shared_ptr<T>& sp)
	{
		os << "Address pointed : "
		<< sp.get() << endl;
		cout << *(sp.m_counter) << endl;
	}

private:
	// Reference counter
	Counter* m_counter;

	// Shared pointer
	T* m_ptr;
};

// Works on Windows but not on MACOS
int main()
{
	// ptr1 pointing to an integer.
	Shared_ptr<int> ptr1(new int(151));
	cout << "--- Shared pointers ptr1 ---\n";
	cout << ptr1;

	{
		// ptr2 pointing to same integer
		// which ptr1 is pointing to
		// Shared pointer reference counter
		// should have increased now to 2.
		Shared_ptr<int> ptr2 = ptr1;
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;

		{
			// ptr3 pointing to same integer
			// which ptr1 and ptr2 are pointing to.
			// Shared pointer reference counter
			// should have increased now to 3.
			Shared_ptr<int> ptr3(ptr2);
			cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
			cout << ptr1;
			cout << ptr2;
			cout << ptr3;
		}

		// ptr3 is out of scope.
		// It would have been destructed.
		// So shared pointer reference counter
		// should have decreased now to 2.
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;
	}

	// ptr2 is out of scope.
	// It would have been destructed.
	// So shared pointer reference counter
	// should have decreased now to 1.
	cout << "--- Shared pointers ptr1 ---\n";
	cout << ptr1;

	return 0;
}
