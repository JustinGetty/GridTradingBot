#include <iostream>
#include <string>
#include <vector>
/*
Strategy:
when X percentage move in price on 5 day moving average and no significant increase/decrese to volume respectively, buy/sell
TP 3/4 at 3% and 1/4 at 5%. SL at 1%

maintain 1 thread for running bot, other thread for calculations
*/

struct StockData{

    std::string timestamp;
    double open;
    double high;
    double close;
    double low;
    double volume;

};

void trade(std::vector<StockData> dataStruct){

    //structure window, slide, alert if moving average goes above X amount
    //this will trigger place trade function
    //store struct of open positions, another 2d vector
    int start = 0;
    int end = 4;


}