#include <bits/stdc++.h>
using namespace std;

class Student {
private:    // Đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    string name;           
    double grade;
    int age;               
    string major;          

public:
    Student(string studentName, double studentGrade, int studentAge = 18, string studentMajor = "Unknown") {  // Nếu không cung cấp age và major thì sử dụng giá trị mặc định
        name = studentName;
        age = studentAge;
        major = studentMajor;

        if (studentGrade >= 0.0 && studentGrade <= 10.0) {  // chỉ nhận điểm hợp lệ từ 0.0 đến 10.0
            grade = studentGrade;
        } else {
            grade = 0.0;  // Nếu điểm không hợp lệ thì đặt về 0
        }
    }

    void displayInfo(){
        cout << "Name:    " << name << endl;
        cout << "Grade:   " << fixed << setprecision(1) << grade << "/10.0" << endl;
        cout << "Age:     " << age << " years old" << endl;
        cout << "Major:   " << major << endl;
        cout << "Status:  " << getGradeStatus() << endl;
    }

    string getGradeStatus(){    // Trả về trạng thái học lực dựa trên điểm số
        if (grade >= 8.5) return "Good";
        else if (grade >= 5.0) return "Average";
        else return "Below Average";
    }

    bool hasBetterGrade(Student otherStudent){    // So sánh điểm giữa hai học sinh
        return this->grade > otherStudent.grade;    // Trả về true nếu học sinh hiện tại có điểm cao hơn học sinh khác
    }

    bool isPassing(double passingGrade = 5.0) const {   // Kiểm tra học sinh có đậu hay không dựa trên điểm chuẩn
        return grade >= passingGrade;   // Trả về true nếu điểm của học sinh lớn hơn hoặc bằng điểm chuẩn
    }

    // Các hàm Getter để truy cập thuộc tính private
    string getName() const { return name; }
    double getGrade() const { return grade; }
    int getAge() const { return age; }
    string getMajor() const { return major; }
};

int main() {
    Student student1("John", 8.5, 20, "Computer Science");
    Student student2("Alice", 9.2, 19, "Mathematics");
    Student student3("Bob", 4.3, 21);  // Sử dụng default major

    student1.displayInfo();
    cout << endl;

    cout << student1.getName() << " (Grade: " << student1.getGrade() << ") - " << student1.getGradeStatus() << endl;
    cout << student3.getName() << " (Grade: " << student3.getGrade() << ") - " << student3.getGradeStatus() << endl;

    // So sánh điểm giữa hai học sinh
    if (student2.hasBetterGrade(student1)) {
        cout << student2.getName() << " has better grade than " << student1.getName() << endl;
    } else {
        cout << student1.getName() << " has better grade than " << student2.getName() << endl;
    }

    // Kiểm tra ai đậu/rớt
    cout << student1.getName() << " is " << (student1.isPassing() ? "PASSING" : "FAILING") << endl; // nếu hàm isPassing trả về true thì in PASSING, ngược lại in FAILING
    cout << student3.getName() << " is " << (student3.isPassing() ? "PASSING" : "FAILING") << endl;

    return 0;
}