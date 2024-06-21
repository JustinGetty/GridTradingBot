#ifndef STOCKDATASTRUCT_H
#define STOCKDATASTRUCT_H

#include <vector>
#include <string>

struct StockData {
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

struct Levels {

    double lvl_one_pos;
    double lvl_two_pos;
    double lvl_three_pos;
    double lvl_four_pos;
    double lvl_one_neg;
    double lvl_two_neg;
    double lvl_three_neg;
    double lvl_four_neg;

};

#endif // STOCKDATASTRUCT_H
