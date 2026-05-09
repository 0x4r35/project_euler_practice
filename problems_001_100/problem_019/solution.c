#include <stdio.h>
#include <stdbool.h>

// Function to check leap year rules
bool is_leap_year(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

// Function to get the correct days in a month, accounting for leap years
int get_days_in_month(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30; // 30 days hath September...
    if (month == 2) return is_leap_year(year) ? 29 : 28;                  // Saving February alone...
    return 31;                                                            // All the rest have 31.
}

int main() {
    // 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday
    int current_day = 1; // 1 Jan 1900 was a Monday
    
    // Fast forward through 1900 to get to 1 Jan 1901
    for (int month = 1; month <= 12; month++) {
        current_day = (current_day + get_days_in_month(month, 1900)) % 7;
    }
    
    int sundays_on_first = 0;
    
    // Start our official count from 1901 to 2000
    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            
            // If the 1st of the month is a 0 (Sunday), tally it!
            if (current_day == 0) {
                sundays_on_first++;
            }
            
            // Advance the calendar to the 1st of the next month
            current_day = (current_day + get_days_in_month(month, year)) % 7;
        }
    }
    
    printf("Total Sundays falling on the first of a month: %d\n", sundays_on_first);
    return 0;
}