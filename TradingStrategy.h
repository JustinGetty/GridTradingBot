#ifndef TRADINGSTRATEGY_H
#define TRADINGSTRATEGY_H

#include <vector>
#include "StockDataStruct.h"

class TradingStrategy {
private:
    double base_price;
    double grid_size;
    int num_of_grids;
    double order_size;
    std::vector<Order> buy_orders;
    std::vector<Order> sell_orders;

public:
    TradingStrategy(double base_price, double grid_size, int num_of_grids, double order_size, 
                    const std::vector<Order>& buy_orders, const std::vector<Order>& sell_orders);
    // Other member functions
};

#endif // TRADINGSTRATEGY_H
