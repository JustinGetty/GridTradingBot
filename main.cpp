#include "DataRead.h"
#include "StockDataStruct.h"
#include <iostream>
#include "Trade.h"

//g++ -o trading_bot main.cpp Trading.cpp DataRead.cpp -std=c++11 -lcurl

int main() {
    //1min, 5min, 15min, 30min, 45min, 1h, 2h, 4h, 1day, 1week, 1month
    std::vector<StockData> historic_data = processHistoricData("tsla", "25", "1day");
	std::cout << std::endl;
    printDataFrame(historic_data);
    StockData origin_candle = historic_data[0];

    Levels levels = setLevels(origin_candle.open);

    visualizeLevels(lvlsToVctr(levels));
    Trade(historic_data, levels);
    
    return 0;
}

