# String Class in C++

- C++ has in its definition a way to represent sequence of characters as an object of class.
- This class is called std::string.
- String class stores the characters as a sequence of bytes with a functionality of allowing access to single byte character.

## std:: string vs Character Array

1. A character array is simply an array of characters can terminated by a null character.
A string is a class which defines objects that can be represented as stream of characters.

2. Size of the character array has to allocated statically,
   more memory cannot be allocated at run time if required.
   Unused allocated memory is wasted in case of character array.

   In case of strings, memory is allocated dynamically.
   More memory can be allocated at run time on demand.
   As no memory is preallocated, no memory is wasted.

3. There is a threat of array decay in case of character array.
   As strings are represented as objects, no array decay occurs.

4. Implementation of character array is faster than std:: string.
   Strings are slower when compared to implementation than character array.

5. Character array do not offer much inbuilt functions to manipulate strings.
   String class defines a number of functionalities which allow manifold operations on strings.


## Operations on strings

### Input Functions

1. **getline()**    : to store a stream of characters as entered by the user in the
                        object memory.
2. **push_back()**  : to input a character at the end of the string.
3. **pop_back()**   : Introduced from C++11(for strings),
                      used to delete the last character from the string.

### Capacity Functions

3. **capacity()**   : This function returns the capacity allocated to the string,
                  which can be equal to or more than the size of the string.
                  Additional space is allocated so that when the new characters
                  are added to the string, the operations can be done efficiently.

4. **resize()**     : This function changes the size of string,
                  the size can be increased or decreased.

5. **length()**     : This function finds the length of the string

6. **shrink_to_fit()** : This function decreases the capacity of the string and
                  makes it equal to its size.
                  This operation is useful to save additional memory if we are
                  sure that no further addition of characters have to be made.

### Iterator Functions

7. **begin()**      : This function returns an iterator to beginning of the string.
8. **end()**        : This function returns an iterator to end of the string.
9. **rbegin()**     : This function returns a reverse iterator pointing at the end
                  of string.
10. **rend()**      : This function returns a reverse iterator pointing at beginning
                  of string.

### Conversion

1.  **to_string()** : Converts an Number into a String

