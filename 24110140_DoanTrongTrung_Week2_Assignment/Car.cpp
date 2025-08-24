#include <bits/stdc++.h>
using namespace std;

class Car {
private:    // đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    string brand;           
    int year;              
    double mileage;        
    string color;        


public:
    Car(string carBrand, int carYear, double carMileage = 0.0, const string& carColor = "White") {  // Nếu không cung cấp mileage và color thì sử dụng giá trị mặc định
        brand = carBrand;
        year = carYear;
        if (carMileage >= 0.0) {    // kiểm tra số km đã đi không âm 
            mileage = carMileage;
        } else {
            mileage = 0.0;  // Nếu số km âm thì đặt mileage về 0
        }
        
        color = carColor;
    }

    void displayInfo() const {
        cout << "Brand:   " << brand << endl;
        cout << "Year:    " << year << endl;
        cout << "Mileage: " << fixed << setprecision(1) << mileage << " km" << endl;
        cout << "Color:   " << color << endl;
    }

    int getAge() const {    // Tính tuổi xe
        return 2025 - year;     // lấy năm hiện tại trừ đi năm sản xuất
    }


    bool isOlder(const Car& otherCar) const {   // So sánh tuổi của hai xe
        return this->year < otherCar.year;  // Trả về true nếu xe hiện tại cũ hơn xe khác
    }

    // Hàm Getter để truy cập các thuộc tính private từ bên ngoài class
    string getBrand() const { return brand; }
    int getYear() const { return year; }
    double getMileage() const { return mileage; }
    string getColor() const { return color; }
};

int main() {
    Car car1("Toyota", 2020, 15000.0, "Red");
    Car car2("Honda", 1995, 200000.5, "Blue"); 
    Car car3("BMW", 2024);  // Sử dụng giá trị mặc định cho mileage và color

    // Hiển thị thông tin của các xe
    car1.displayInfo();
    cout << endl;

    // Kiểm tra các hàm Getter và hàm getAge
    cout << car1.getBrand() << " (" << car1.getYear() << ") is " << car1.getAge() << " years old" << endl;
    cout << car2.getBrand() << " (" << car2.getYear() << ") is " << car2.getAge() << " years old" << endl;
    
    // Kiểm tra hàm isOlder
    if (car2.isOlder(car1)) {
        cout << car2.getBrand() << " is older than " << car1.getBrand() << endl;
    } else {
        cout << car1.getBrand() << " is older than " << car2.getBrand() << endl;
    }

    return 0;
}