#ifndef DATAREAD_H
#define DATAREAD_H

#include <vector>
#include "StockDataStruct.h"

std::vector<StockData> processHistoricData(const std::string symbol, const std::string period, const std::string interval);
void printData(const StockData data);

#endif // DATAREAD_H
