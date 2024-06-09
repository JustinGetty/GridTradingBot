#include "DataRead.cpp"
#include <vector>



int main() {

    std::vector<StockData> historic_data = processHistoricData("tsla", "15d", "1h");
	std::cout << std::endl;
    std::cout << "Timestamp            Open         High         Low          Close        Volume" << std::endl;
		
        for(size_t i = 0; i < 1; i++){
            printData(historic_data[i]);
        }
		
        std::cout << std::endl;
    return 0;
}

