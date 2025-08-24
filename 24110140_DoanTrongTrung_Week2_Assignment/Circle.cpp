#include <bits/stdc++.h>
using namespace std;

class Circle {
private:    // Đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    double radius;          
    string color;

public:
    Circle(double r = 1.0, string c = "Red") {  // Nếu không cung cấp radius và color thì sử dụng giá trị mặc định
        if (r > 0) { // chỉ nhận giá trị bán kính hợp lệ (lớn hơn 0)
            radius = r;
        } else {
            radius = 1.0;  // Nếu bán kính không hợp lệ thì đặt về 1.0
        }
        color = c;
    }

    void displayInfo() {
        cout << "Radius:        " << radius << " units" << endl;
        cout << "Color:         " << color << endl;
        cout << "Circumference: " << circumference() << " units" << endl;
        cout << "Area:          " << area() << " square units" << endl;
        cout << "Valid radius:  " << (isRadiusPositive() ? "Yes" : "No") << endl;
    }

    double circumference() {
        return 2 * M_PI * radius;
    }

    double area() {
        return M_PI * radius * radius;
    }

    // Kiểm tra bán kính có hợp lệ không
    bool isRadiusPositive() {
        return radius > 0;
    }
};

int main() {
    // Tạo hình tròn bằng cách nhập từ người dùng
    Circle circle1;
    double inputRadius;
    string inputColor;

    cout << "Nhập bán kính hình tròn: ";
    cin >> inputRadius;
    cin.ignore();
    cout << "Nhập màu sắc hình tròn: ";
    getline(cin, inputColor);
    circle1 = Circle(inputRadius, inputColor);      // Tạo circle với input từ người dùng
    
    circle1.displayInfo();
    cout << endl;
    
    // Test với các giá trị khác
    Circle circle2(5.5, "Blue");   // Hình tròn bán kính 5.5, màu xanh
    Circle circle3(-2.0, "Green"); // Test với bán kính âm
    Circle circle4;                // Sử dụng default values
    
    cout << "\nCircle 2:" << endl;
    circle2.displayInfo();
    
    cout << "\nCircle 3 (with negative radius):" << endl;
    circle3.displayInfo();
    
    cout << "\nCircle 4 (default values):" << endl;
    circle4.displayInfo();

    return 0;
}