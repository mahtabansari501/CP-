#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    cout << "Enter your name: ";
    getline(cin, name); // take full line input

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello, " << name << "! You are " << age << " years old." << endl;

    return 0;
}

