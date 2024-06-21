#ifndef TRADE_H
#define TRADE_H

#include "StockDataStruct.h"

void Trade(std::vector<StockData> stock_frame, Levels levels);
Levels setLevels(double base_price);
void visualizeLevels(std::vector<double> level_vctr);
std::vector<double> lvlsToVctr(Levels levels);

#endif