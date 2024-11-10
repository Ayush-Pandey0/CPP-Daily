#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

const string API_KEY = "your_api_key";  // Replace with your OpenWeatherMap API key
const string BASE_URL = "http://api.openweathermap.org/data/2.5/weather?q=";

// Function to store the response from the curl request
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to get weather information
string get_weather(const string& city) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        string url = BASE_URL + city + "&appid=" + API_KEY + "&units=metric";
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        if (res != CURLE_OK) {
            cerr << "Failed to get weather data: " << curl_easy_strerror(res) << endl;
            return "Error fetching data";
        }
    }

    return readBuffer;
}

// Function to display weather data
void display_weather(const string& weather_json) {
    try {
        json weather_data = json::parse(weather_json);

        string city = weather_data["name"];
        double temperature = weather_data["main"]["temp"];
        int humidity = weather_data["main"]["humidity"];
        string weather_description = weather_data["weather"][0]["description"];

        cout << "City: " << city << endl;
        cout << "Temperature: " << temperature << "°C" << endl;
        cout << "Humidity: " << humidity << "%" << endl;
        cout << "Condition: " << weather_description << endl;

    } catch (const json::exception& e) {
        cerr << "Error parsing JSON data: " << e.what() << endl;
    }
}

int main() {
    string city;

    cout << "Enter city name: ";
    getline(cin, city);

    // Fetch the weather data
    string weather_json = get_weather(city);

    // Display the parsed weather data
    if (!weather_json.empty()) {
        display_weather(weather_json);
    }

    return 0;
}
