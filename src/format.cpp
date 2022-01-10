#include <string>
#include <iomanip>

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
    
    std::ostringstream stream;

    stream << std::setw(2) << std::setfill('0') << hour << ":" 
     << std::setw(2) << std::setfill('0') << minutes << ":"
     << std::setw(2) << std::setfill('0') << secs;

    return stream.str();
}