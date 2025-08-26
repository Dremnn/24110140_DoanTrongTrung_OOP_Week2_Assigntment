#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:    // Đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    double width;           
    double height;
    string color;

public:
    Rectangle(double rectangleWidth, double rectangleHeight, const string& rectangleColor = "White") {  // Nếu không cung cấp color thì sử dụng giá trị mặc định
        if (rectangleWidth > 0) {    // Kiểm tra chiều rộng phải dương
            width = rectangleWidth;
        } else {
            width = 1.0;  // Nếu chiều rộng không hợp lệ thì đặt về 1.0
        }
        
        if (rectangleHeight > 0) {   // Kiểm tra chiều cao phải dương
            height = rectangleHeight;
        } else {
            height = 1.0;  // Nếu chiều cao không hợp lệ thì đặt về 1.0
        }
        
        color = rectangleColor;
    }

    double calculateArea() const {    // Tính diện tích hình chữ nhật
        return width * height;
    }

    double calculatePerimeter() const {   // Tính chu vi hình chữ nhật
        return 2 * (width + height);
    }

    string getShapeType() const {    // Phân loại hình dựa trên tỷ lệ chiều rộng và chiều cao
        if (width == height) return "Square";
        else return "Rectangle";
    }

    bool hasLargerArea(const Rectangle& otherRectangle) const {    // So sánh diện tích giữa hai hình chữ nhật
        return this->calculateArea() > otherRectangle.calculateArea();    // Trả về true nếu hình chữ nhật hiện tại có diện tích lớn hơn hình chữ nhật khác
    }

    // Các hàm Getter để truy cập thuộc tính private
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    string getColor() const { return color; }
};

int main() {
    Rectangle rect1(5.0, 10.0, "Red");
    Rectangle rect2(8.0, 8.0);  // Sử dụng default color

    // Test 1: Kiểm tra diện tích
    cout << "Rectangle 1 area: " << rect1.calculateArea() << endl;
    cout << "Rectangle 2 area: " << rect2.calculateArea() << endl;
    cout << endl;

    // Test 2: Kiểm tra chu vi
    cout << "Rectangle 1 perimeter: " << rect1.calculatePerimeter() << endl;
    cout << "Rectangle 2 perimeter: " << rect2.calculatePerimeter() << endl;
    cout << endl;

    // Test 3: Kiểm tra loại hình
    cout << "Rectangle 1 type: " << rect1.getShapeType() << endl;
    cout << "Rectangle 2 type: " << rect2.getShapeType() << endl;
    cout << endl;

    // Test 4: So sánh diện tích
    if (rect1.hasLargerArea(rect2)) {
        cout << "Rectangle 1 has larger area than Rectangle 2" << endl;
    } else {
        cout << "Rectangle 2 has larger area than Rectangle 1" << endl;
    }
    cout << endl;
    
    return 0;
}