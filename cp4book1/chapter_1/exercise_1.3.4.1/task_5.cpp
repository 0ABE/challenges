/**
 *  .d8888b.        d8888 888888b.   8888888888
 * d88P  Y88b      d88888 888  "88b  888
 * 888    888     d88P888 888  .88P  888
 * 888    888    d88P 888 8888888K.  8888888
 * 888    888   d88P  888 888  "Y88b 888
 * 888    888  d88P   888 888    888 888
 * Y88b  d88P d8888888888 888   d88P 888
 *  "Y8888P" d88P     888 8888888P"  8888888888
 *
 * Copyright (c) 2025, Abe Mishler
 * Licensed under the Universal Permissive License v 1.0
 * as shown at https://oss.oracle.com/licenses/upl/.
 */

#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tuple>

typedef std::tuple<int, int, int> Date_t;
typedef std::multiset<Date_t> Sorted_t;

// Number of days per month.
int dpm[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Print the date in "MM DD YYYY" format.
void
print(const Date_t* date)
{
    int year, month, day;
    std::tie(year, month, day) = *date;
    printf("%02d %02d %4d\n", month, day, year);
}

int
main(int argc, char* argv[])
{
    // Seed the random number generator.
    srand(time(NULL));

    // Get user input for number of dates.
    int n;
    scanf("%d", &n);

    // Allocate memory for n dates in a list.
    Date_t* dates = (Date_t*)malloc(n * sizeof(Date_t));
    // Init the list of dates.
    for (int i = 0; i < n; ++i) {
        int year = (rand() % (2025 - 1900 + 1)) + 1900;
        int month = (rand() % 12) + 1;
        int day = (rand() % dpm[month]) + 1;
        dates[i] = { year, month, day };
    }

    // Get ready to sort.
    Sorted_t sorted_dates;
    // Insert the dates into the sorted ds.
    for (int i = 0; i < n; ++i)
        sorted_dates.insert(dates[i]);

    // The trick is recognizing that multiset is a red-black tree
    // which stores data sorted so all we have to do is print the
    // dates as we traverse through the ds.
    printf("MM DD YYYY\n----------\n");
    for (const auto &date : sorted_dates)
        print(&date);
}
