// Siemens Software Engineering test - Katherine Neul.cpp
//

#include <iostream>
#include <chrono>  
#include <ctime>
#include <map>
#include <string>

#include <vector>

using namespace std;

void setupAirports(map<string, time_t>& timeLastLanding, const vector<string>& airports);

int main()
{
    vector<string> airports = { "LGW", "EMA", "MAN" };
    map<string, time_t> timeLastLanding;
    int timeBeforeLanding = 60;
    setupAirports(timeLastLanding, airports);

    /*
     * I assume this system would be waiting for btye arrays in a realistic scenario but because
     * I want to demonstarate code that is funtional I will make it so that user input manages 
     * the system, albeit impractical. 
    */

    while (1) {
        string airport;

        // User input
        cout << "Enter the airport id for where the plane will land. (LGW, EMA, MAN) " << endl;
        cin >> airport;

        // validate input
        if (timeLastLanding.find(airport) == timeLastLanding.end()) {
            cout << "Invalid airport ID. try again." << endl;
            continue;
        }

        // current time
        time_t timeCurrent;
        time(&timeCurrent);

        // time between the last landing and now
        double timeSinceLastLanding = difftime(timeCurrent, timeLastLanding[airport]);

        // Check if enough time has passed? 
        if (timeSinceLastLanding >= timeBeforeLanding) 
        {
            cout << "Plane successfully landed at " << airport << "!\n";
            cout << "\n";
            timeLastLanding[airport] = timeCurrent; // Updatng landing time
        }
        else 
        {
            int timeRemaining = timeBeforeLanding - static_cast<int>(timeSinceLastLanding);
            cout << "This plane cannot land at " << airport << ". Please wait for " << timeRemaining << " seconds.\n";
            cout << "\n";
        }
    }

    return 0;
}

void setupAirports(map<string, time_t>& timeLastLanding, const vector<string>& airports) {
    for (const auto& a : airports) {
        timeLastLanding[a] = 0;
    }
}