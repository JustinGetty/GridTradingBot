#include <iostream>
#include <string>
/*
Strategy:
when X percentage move in price on 5 day moving average and no significant increase/decrese to volume respectively, buy/sell
TP 3/4 at 3% and 1/4 at 5%. SL at 1%


*/

struct StockData{

    std::string timestamp;
    double open;
    double high;
    double close;
    double low;
    double volume;

};