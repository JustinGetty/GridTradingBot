#include <iostream>
#include <utility>
#include "StockDataStruct.h"
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

    TradingStrategy(double base_price, double grid_size, int num_of_grids, 
    double order_size, std::vector<Order>& buy_orders, std::vector<Order>& sell_orders) : 
    base_price(base_price), grid_size(grid_size), num_of_grids(num_of_grids), 
    order_size(order_size), buy_orders(buy_orders), sell_orders(sell_orders){



        
    };




};