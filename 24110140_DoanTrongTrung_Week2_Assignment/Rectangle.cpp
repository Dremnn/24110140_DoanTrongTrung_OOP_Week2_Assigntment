#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle( int w , int h ) {   
        width = w;
        height = h;
    }

    int calculateArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect1(5, 10);
    cout << "Area: " << rect1.calculateArea() << endl;

    return 0;
}
