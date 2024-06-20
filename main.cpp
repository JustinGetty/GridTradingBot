#include "DataRead.h"
#include "StockDataStruct.h"
#include <iostream>

//g++ -o trading_bot main.cpp Trading.cpp DataRead.cpp -std=c++11 -lcurl

int main() {

    std::vector<StockData> historic_data = processHistoricData("tsla", "15d", "1h");
	std::cout << std::endl;
    std::cout << " Timestamp            Open         High         Low          Close        Volume" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;	
        for(size_t i = 0; i < 49; i++){
            printData(historic_data[i]);
        }
		
        std::cout << std::endl;
    return 0;
}

