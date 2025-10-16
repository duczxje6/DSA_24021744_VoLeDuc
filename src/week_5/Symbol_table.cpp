#include <iostream>
using namespace std;
#include <string>
#include <vector>
struct Symbol{
    string name;        // Tên biến
    string type;        // Kiểu dữ liệu
    int size;           // Kích thước
    int address;        // Địa chỉ
};
struct SymbolTable{
    vector<Symbol> table;   // Bảng ký hiệu dưới dạng vector        
    int currentAddress;     // Địa chỉ hiện tại để cấp phát
    SymbolTable() {
        currentAddress = 0;  // Khởi tạo địa chỉ hiện tại
    }
    // Hàm thêm ký hiệu mới
    void addSymbol(string name, string type, int size) {
        Symbol sym;
        sym.name = name;
        sym.type = type;
        sym.size = size;
        sym.address = currentAddress;
        table.push_back(sym);