#include <bits/stdc++.h>
using namespace std;

class Account {
private:    // Đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    string accountNumber;
    double balance;
    string ownerName;
    double minBalance; 

public:
    Account(string accNumber, string name, double initialBalance, double minimunBalance = 100.0){    // Nếu không cung cấp minBalance thì sử dụng giá trị mặc định 100.0
    accountNumber = accNumber;
    ownerName = name;
    minBalance = minimunBalance;
    balance = initialBalance;
}

    void deposit(double amount) {   
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance - minBalance) {    // Kiểm tra có đủ tiền để rút không (phải giữ lại minBalance)
            cout << "Withdrawal denied! Must maintain at least " << minBalance << " VND in account." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << " VND" << endl;
        }
    }

    void displayBalance() {
        cout << "Owner's Name: " << ownerName << endl;
        cout << "Current balance: " << balance << " VND" << endl;
    }
};

int main() {
    Account acc1("123456789", "Nguyen Van A", 1000.0, 100.0);
    
    acc1.displayBalance();
    acc1.deposit(500);
    acc1.displayBalance();
    acc1.withdraw(200);
    acc1.displayBalance();
    
    // Thử rút số tiền vượt quá số dư tối thiểu
    acc1.withdraw(1500); 
    acc1.displayBalance();

    return 0;
}