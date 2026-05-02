#include <iostream>
#include <vector>

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int main() {
    // Days in each month. The 0 at the start is a dummy placeholder so index 1 = Jan, 12 = Dec.
    std::vector<int> days_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int current_day = 1; // 1 Jan 1900 (Monday = 1)

    // Advance to 1 Jan 1901
    for (int m = 1; m <= 12; ++m) {
        int days = days_in_month[m];
        if (m == 2 && isLeapYear(1900)) days = 29;
        current_day = (current_day + days) % 7;
    }

    int sunday_count = 0;

    for (int year = 1901; year <= 2000; ++year) {
        for (int m = 1; m <= 12; ++m) {
            
            if (current_day == 0) { // 0 represents Sunday
                sunday_count++;
            }
            
            int days = days_in_month[m];
            if (m == 2 && isLeapYear(year)) {
                days = 29;
            }
            
            current_day = (current_day + days) % 7;
        }
    }

    std::cout << "Total Sundays falling on the first of a month: " << sunday_count << std::endl;
    return 0;
}