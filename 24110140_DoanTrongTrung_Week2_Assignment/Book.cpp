#include <bits/stdc++.h>
using namespace std;

class Book {
private:    // Đặt các thuộc tính là private để đảm bảo tính đóng gói và bảo mật dữ liệu
    string title;           
    string author;
    int pages;               
    double price;          

public:
    Book(string bookTitle, string bookAuthor, int bookPages = 100, double bookPrice = 0.0) {  // Nếu không cung cấp pages và price thì sử dụng giá trị mặc định
        title = bookTitle;
        author = bookAuthor;
        
        if (bookPages > 0){ // chỉ nhận giá trị số trang hợp lệ (lớn hơn 0)
            pages = bookPages;
        } else {
            pages = 100;  // Nếu số trang không hợp lệ thì đặt về 100
        }
        
        if (bookPrice >= 0.0) { // chỉ nhận giá trị giá hợp lệ (không âm)
            price = bookPrice;
        } else {
            price = 0.0;  // Nếu giá âm thì đặt về 0
        }
    }

    void displayInfo(){
        cout << "Title:   " << title << endl;
        cout << "Author:  " << author << endl;
        cout << "Pages:   " << pages << " pages" << endl;
        cout << "Price:   $" << fixed << setprecision(2) << price << endl;
    }

    bool isMoreExpensive(Book otherBook){    // So sánh giá giữa hai cuốn sách
        return this->price > otherBook.price;    // Trả về true nếu sách hiện tại đắt hơn sách khác
    }

    bool isAffordable(double budget){   // Kiểm tra sách có nằm trong ngân sách không
        return price <= budget;   // Trả về true nếu giá sách nhỏ hơn hoặc bằng ngân sách
    }

    // Các hàm Getter để truy cập thuộc tính private
    string getTitle(){ return title; }
    string getAuthor(){ return author; }
    int getPages(){ return pages; }
    double getPrice(){ return price; }
};

int main() {
    Book book1("C++ Programming", "Bjarne Stroustrup", 800, 45.99);
    Book book2("Clean Code", "Robert Martin", 464, 35.50);
    Book book3("Python Basics", "John Smith", 150);  // Sử dụng default price

    book1.displayInfo();
    cout << endl;

    // So sánh giá giữa hai cuốn sách
    if (book1.isMoreExpensive(book2)) {
        cout << book1.getTitle() << " is more expensive than " << book2.getTitle() << endl;
    } else {
        cout << book2.getTitle() << " is more expensive than " << book1.getTitle() << endl;
    }

    // Kiểm tra sách nào nằm trong ngân sách
    double budget = 50.0;   // Ngân sách $50
    cout << book1.getTitle() << " is " << (book1.isAffordable(budget) ? "AFFORDABLE" : "EXPENSIVE") << " (budget: $50)" << endl; // nếu hàm isAffordable trả về true thì in AFFORDABLE, ngược lại in EXPENSIVE
    cout << book2.getTitle() << " is " << (book2.isAffordable(budget) ? "AFFORDABLE" : "EXPENSIVE") << " (budget: $50)" << endl;

    return 0;
}