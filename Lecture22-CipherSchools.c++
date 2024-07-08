/*
This program demonstrates the use of pointers in C++.
It shows how to declare a pointer, assign it the address of a variable,
and use the pointer to access and modify the value of the variable.
*/

#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable 'a' and initialize it to 10
    int a = 10;
    
    // Declare a pointer 'p' and assign it the address of 'a'
    int *p = &a;
    
    // Output the value of 'a'
    cout << "The value of a is: " << a << endl;
    
    // Output the address of 'a'
    cout << "The address of a is: " << p << endl;
    
    // Change the value of 'a' using the pointer 'p'
    *p = 20;
    
    // Output the changed value of 'a'
    cout << "Changing value of a using pointer: " << *p << endl;
    
    return 0;
}
