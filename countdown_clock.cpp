#include <iostream>
#include <ctime>
using namespace std;
class CountdownClock {
private:
   string eventName;
    time_t currentTime;
    time_t futureTime;
    double timeDifference;
    tm futureDate = {};
public:
//constructor to initialize the countdown clock
    CountdownClock() {
        eventName = "";
        currentTime = 0;
        futureTime = 0;
        timeDifference = 0.0;
    }
    void setEventName() {
        cout << "Enter the name of the event: ";
        cin.ignore();
        getline(cin, eventName);
    }
    void setCurrentTime() {
        currentTime = time(0);
    }
    void setFutureTime() {
        cout << "Enter future date and time for the event(YYYY MM DD HH MM SS): ";
        cin >> futureDate.tm_year >> futureDate.tm_mon >> futureDate.tm_mday
            >> futureDate.tm_hour >> futureDate.tm_min >> futureDate.tm_sec;
        futureDate.tm_year -= 1900; // Adjust year for tm structure
        futureDate.tm_mon -= 1;     // Adjust month for tm structure
        futureTime = mktime(&futureDate);
    }
    
    void calculateTimeDifference() {
        currentTime = time(0);
        timeDifference = difftime(futureTime, currentTime);
    }

    void displayCountdown() {
        if (timeDifference > 0) {
            int days = timeDifference / (60 * 60 * 24);
            int hours = (timeDifference - days * 60 * 60 * 24) / (60 * 60);
            int minutes = (timeDifference - days * 60 * 60 * 24 - hours * 60 * 60) / 60;
            int seconds = timeDifference - days * 60 * 60 * 24 - hours * 60 * 60 - minutes * 60;

            cout << "Countdown to " << eventName << ": "
                 << days << " days, "
                 << hours << " hours, "
                 << minutes << " minutes, "
                 << seconds << " seconds." << endl;
        } else {
            cout << "The event " << eventName << " has already occurred." << endl;
        }
    }
};

int main() {
    CountdownClock clock;
    clock.setEventName();
    clock.setFutureTime();
    clock.calculateTimeDifference();
    clock.displayCountdown();
    return 0;
}