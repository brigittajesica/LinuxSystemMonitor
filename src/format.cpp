#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    int hour = (int) (seconds / (60 * 60));
    int minutes = (int) ((seconds % (60* 60)) / 60);
    int secs = (int) (seconds - (hour * 60 * 60) - (minutes * 60));
    string output = std::to_string(hour) + ":" + std::to_string(minutes) + ":" + std::to_string(secs);
    return output;
}