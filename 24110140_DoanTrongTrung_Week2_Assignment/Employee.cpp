#include <bits/stdc++.h>
using namespace std;

class Employee {
private:    // Đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    string name;           
    double salary;
    int experience;      
    string department;          

public:
    Employee(string employeeName, double employeeSalary, int employeeExperience = 1,string employeeDepartment = "Unknown") {  // Nếu không cung cấp experience và department thì sử dụng giá trị mặc định
        name = employeeName;
        department = employeeDepartment;
        salary = employeeSalary;
        
        if (employeeExperience >= 0) {
            experience = employeeExperience;
        } else {
            experience = 1;  // Nếu kinh nghiệm không hợp lệ thì đặt về 1 năm
        }
    }

    void displayInfo(){
        cout << "Name:        " << name << endl;
        cout << "Salary:      $" << fixed << setprecision(2) << salary << endl;
        cout << "Experience:  " << experience << " years" << endl;
        cout << "Department:  " << department << endl;
        cout << "Level:       " << getEmployeeLevel() << endl;
    }

    string getEmployeeLevel(){    // Phân loại nhân viên dựa trên số năm kinh nghiệm
        if (experience >= 10) return "Senior";
        else if (experience >= 5) return "Mid-level";
        else if (experience >= 2) return "Junior";
        else return "Entry-level";
    }

    bool hasHigherSalary(Employee otherEmployee){    // So sánh lương giữa hai nhân viên
        return this->salary > otherEmployee.salary;    // Trả về true nếu nhân viên hiện tại có lương cao hơn nhân viên khác
    }

    bool isHighEarner(double threshold = 60000.0){   // Kiểm tra nhân viên có thu nhập cao không
        return salary >= threshold;   // Trả về true nếu lương của nhân viên lớn hơn hoặc bằng ngưỡng
    }

    // Các hàm Getter để truy cập thuộc tính private
    string getName(){ return name; }
    double getSalary(){ return salary; }
    int getExperience(){ return experience; }
    string getDepartment(){ return department; }
};

int main() {
    Employee employee1("Alice", 75000.0, 8, "Engineering");
    Employee employee2("Charlie", 55000.0, 12);  // Sử dụng default department

    employee1.displayInfo();
    cout << endl;
    employee1.displayInfo();
    cout << endl;

    // Kiểm tra trinh độ nhân viên
    cout << employee1.getName() << " (Salary: $" << employee1.getSalary() << ") - " << employee1.getEmployeeLevel() << endl;
    cout << employee2.getName() << " (Salary: $" << employee2.getSalary() << ") - " << employee2.getEmployeeLevel() << endl;

    // So sánh lương giữa hai nhân viên
    if (employee1.hasHigherSalary(employee2)) {
        cout << employee1.getName() << " has higher salary than " << employee2.getName() << endl;
    } else {
        cout << employee2.getName() << " has higher salary than " << employee1.getName() << endl;
    }

    // Kiểm tra ai là high earner
    cout << employee1.getName() << " is " << (employee1.isHighEarner() ? "HIGH EARNER" : "REGULAR EARNER") << " (threshold: $60,000)" << endl; // nếu hàm isHighEarner trả về true thì in HIGH EARNER, ngược lại in REGULAR EARNER
    cout << employee2.getName() << " is " << (employee2.isHighEarner() ? "HIGH EARNER" : "REGULAR EARNER") << " (threshold: $60,000)" << endl;

    return 0;
}