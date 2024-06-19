#include <vector>
#include <string>
struct StockData{

    std::string timestamp;
    double open;
    double high;
    double close;
    double low;
    double volume;

};

struct Order {
    double price;
    double amount;
    std::string type;
};