#include <iostream>
using namespace std;

class Rectangle {
public:
    int width;
    int height;

    int calculateArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect1;
    rect1.width = 5;
    rect1.height = 10;
    cout << "Area: " << rect1.calculateArea() << endl;

    return 0;
}
