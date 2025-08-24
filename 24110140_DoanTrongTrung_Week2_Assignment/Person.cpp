#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int age;
    string address;
    string phoneNumber;

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
    }

    bool isAdult() {
        return age >= 18;
    }

    void move(string newAddress){
        address = newAddress;
    }

    void greet(){
        cout << "Hello, my name is " << name << endl;
    }
};

int main() {
    Person person1;
    person1.name = "John Doe";
    person1.age = 20;
    person1.address = "123 Main St";
    person1.phoneNumber = "1234567890";

    person1.displayInfo();
    cout << endl;

    if (person1.isAdult()) {
        cout << "This person is an adult." << endl;
    } else {
        cout << "This person is not an adult." << endl;
    }

    person1.move("36 Main St");
    person1.displayInfo();
    cout << endl;

    person1.greet();

    return 0;
}
