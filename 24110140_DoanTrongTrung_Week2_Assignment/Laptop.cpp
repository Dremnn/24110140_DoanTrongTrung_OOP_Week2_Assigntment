//Generated with assistance from ChatGPT.
#include <bits/stdc++.h>
using namespace std;

class Laptop {
public:
    string brand;
    string model;
    int ram; // Dung lượng RAM tính bằng GB
    int storage; // Dung lượng ổ cứng tính bằng GB
    string gpu;

    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "GPU: " << gpu << endl;
    }

    void checkRAM(int requiredRAM) {
        if (ram >= requiredRAM) {
            cout << "This laptop has enough RAM to run the software." << endl;
        } else {
            cout << "This laptop does not have enough RAM to run the software." << endl;
        }
    }

    void checkGPU(string requiredGPU) {
        // Danh sách các GPU theo thứ tự từ yếu đến mạnh
        vector<string> gpuRank = {
            "Intel HD", "Intel Iris Xe", "GTX 1050", "GTX 1650", 
            "GTX 1660 Ti", "RTX 3060", "RTX 3070", "RTX 3080"
        };

        auto userGPU = find(gpuRank.begin(), gpuRank.end(), gpu);   // Tìm vị trí GPU của người dùng trong danh sách
        auto minGPU = find(gpuRank.begin(), gpuRank.end(), requiredGPU);    // Tìm vị trí GPU tối thiểu yêu cầu trong danh sách

        if (userGPU == gpuRank.end() || minGPU == gpuRank.end()) {  // Nếu không tìm thấy GPU trong danh sách
            cout << "Unknown GPU name" << endl;
        } else if (userGPU >= minGPU) { // GPU của người dùng mạnh hơn hoặc bằng GPU tối thiểu yêu cầu
            cout << "This laptop has a GPU strong enough for gaming." << endl;
        } else {    // GPU của người dùng yếu hơn GPU tối thiểu yêu cầu
            cout << "This laptop's GPU is weaker than required for gaming." << endl;
        }
    }

    void  upgradeRAM(int additionalRAM){
        ram += additionalRAM;
    }
};

int main() {
    Laptop laptop1;
    laptop1.brand = "Dell";
    laptop1.model = "XPS 13";
    laptop1.ram = 8;
    laptop1.storage = 256;
    laptop1.gpu = "RTX 3060";

    laptop1.displayInfo();

    // Kiểm tra xem laptop có đủ RAM để chạy phần mềm yêu cầu 16GB RAM
    laptop1.checkRAM(16);
    // Kiểm tra xem gpu của laptop có đủ mạnh để chơi game với gpu tối thiểu là GTX 1050 
    laptop1.checkGPU("GTX 1050");

    // Nâng cấp RAM thêm 16GB
    laptop1.upgradeRAM(16);
    laptop1.displayInfo();
    
    return 0;
}
