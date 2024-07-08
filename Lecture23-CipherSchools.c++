/*
This program demonstrates the concept of scale factor in pointer arithmetic.
It also shows how to use pointers with arrays.
*/

#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable 'a' and initialize it to 10
    int a = 10;
    
    // Declare a pointer 'p' and assign it the address of 'a'
    int *p = &a;
    
    // Declare an array of 5 integers
    int arr[5];
    
    // Output the address of 'a' and the address obtained by adding 1 to the pointer 'p'
    cout << "Address of a: " << &a << endl;
    cout << "Address after adding 1 to pointer p: " << p + 1 << endl;
    
    // Input values into the array
    cout << "Enter 5 integer values for the array:" << endl;
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    // Output the addresses of the elements in the array
    cout << "Addresses of the array elements:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << &arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
