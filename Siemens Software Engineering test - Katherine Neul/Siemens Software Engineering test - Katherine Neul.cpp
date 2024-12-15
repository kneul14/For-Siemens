// Siemens Software Engineering test - Katherine Neul.cpp
//

#include <iostream>
#include <chrono>  
#include <ctime>
#include <map>
#include <string>

using namespace std;

int main()
{
    const char* airports[] = {"LGW", "EMA", "MAN"};
    map<string, time_t> timeLastLanding;
    int timeBeforeLanding = 60;
    time_t timeCurrent;
    time(&timeCurrent);
    string airport;
    bool exists = 1;

    for (auto& a : airports) {
        timeLastLanding[a] = 0;
    }

    /*
     * I assume this system would be waiting for btye arrays in a realistic scenario but because
     * I want to demonstarate code that is funtional I will make it so that user input manages 
     * the system, albeit impractical. 
    */

    while (1) {
        string airport;

        // Prompt user for input
        cout << "Enter the airport id for wheree the plane will land. (LGW, EMA, MAN) ";
        cin >> airport;

        // Validate input
        if (timeLastLanding.find(airport) == timeLastLanding.end()) {
            cout << "Invalid airport ID. Please try again.\n";
            continue;
        }
    }

    return 0;
}

