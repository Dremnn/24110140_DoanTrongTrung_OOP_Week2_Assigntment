#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;
    string phoneNumber;
public:
    Person(string n , int a , string addr , string phone) {
        name = n;
        age = a;
        address = addr;
        phoneNumber = phone;
    }
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
    Person person1("Jane Doe", 17, "456 Main St", "0987654321");
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
