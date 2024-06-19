#include <iostream>
#include <utility>
#include "StockDataStruct.cpp"
/*
Strategy:
Grid bot


*/
class TradingStrategy{

private:

    double base_price;
    double grid_size;
    int num_of_grids;
    double order_size;
    std::vector<Order> buy_orders;
    std::vector<Order> sell_orders;

public:

    TradingStrategy(double base_price, double grid_size, int num_of_grids, double order_size)


};