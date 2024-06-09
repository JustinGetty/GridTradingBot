#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>  
#include <fstream>
#include <vector>

using namespace std;
using json = nlohmann::json;


//std::string api_key = "https://yahoo-finance127.p.rapidapi.com/historic/tsla/1h/15d";


std::string defineStockParams(string ticker, string range, string granularity){

    std::string requestStr = "https://yahoo-finance127.p.rapidapi.com/historic/";

    std::string combined = requestStr + ticker + "/" + granularity + "/" + range;
    return combined;

}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::vector<std::vector<double>> processHistoricData(string ticker, string range, string granularity)
{
    CURL* hnd;
    CURLcode ret;
    std::string readBuffer;

    string api_key = defineStockParams(ticker, range, granularity);

    std::vector<std::vector<double>> stock_data;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    hnd = curl_easy_init();
    if(hnd) {
        curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(hnd, CURLOPT_URL, api_key.c_str());

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "x-rapidapi-key: b5a656e741mshf96723c09bf1ce5p1506c7jsn4183363ab252");
        headers = curl_slist_append(headers, "x-rapidapi-host: yahoo-finance127.p.rapidapi.com");
        curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &readBuffer);

        ret = curl_easy_perform(hnd);
        if(ret != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(ret));
        } else {
            try {
                auto json_response = json::parse(readBuffer);
                //prints raw json - ignore
                //std::cout << "Parsed JSON: " << json_response.dump(4) << std::endl;

                
                std::vector<double> timestamps;
                std::vector<double> opens;
                std::vector<double> highs;
                std::vector<double> lows;
                std::vector<double> closes;
                std::vector<double> volumes;

                if (json_response.contains("timestamp") && json_response.contains("indicators") && json_response["indicators"].contains("quote")) {
                    auto json_timestamps = json_response["timestamp"];
                    auto quotes = json_response["indicators"]["quote"][0];

                    auto json_opens = quotes["open"];
                    auto json_highs = quotes["high"];
                    auto json_lows = quotes["low"];
                    auto json_closes = quotes["close"];
                    auto json_volumes = quotes["volume"];

                    for (size_t i = 0; i < json_timestamps.size(); ++i) {
                        timestamps.push_back(json_timestamps[i]);
                        opens.push_back(json_opens[i]);
                        highs.push_back(json_highs[i]);
                        lows.push_back(json_lows[i]);
                        closes.push_back(json_closes[i]);
                        volumes.push_back(json_volumes[i]);
                    }

                    stock_data.push_back(timestamps);
                    stock_data.push_back(opens);
                    stock_data.push_back(highs);
                    stock_data.push_back(lows);
                    stock_data.push_back(closes);
                    stock_data.push_back(volumes);

                    
                } else {
                    std::cout << "Expected keys not found in JSON response." << std::endl;
                }
            } catch (json::parse_error& e) {
                std::cerr << "JSON parse error: " << e.what() << std::endl;
            }
        }

        curl_easy_cleanup(hnd);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
    return stock_data;
}


int main() {

    std::vector<std::vector<double>> historic_data = processHistoricData("tsla", "15d", "1h");
    std::cout << "Timestamp, Open, High, Low, Close, Volume" << std::endl;
        for(size_t i = 0; i < (sizeof(historic_data[0])); i++){
            std::cout << historic_data[0][i] << " | "
                      << historic_data[1][i] << " | "
                      << historic_data[2][i] << " | "
                      << historic_data[3][i] << " | "
                      << historic_data[4][i] << "\n";
        }
        std::cout << std::endl;
    return 0;
}
