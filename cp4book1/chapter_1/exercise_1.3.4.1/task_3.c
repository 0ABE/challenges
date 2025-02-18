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

#include <stdio.h>
#include <time.h>

typedef struct tm tm_struct;

int
main(int argc, char* argv[])
{
    // Get the current time in secs.
    time_t now_secs;
    time(&now_secs);

    // Get the date in the past from user input.
    int year, month, day;
    printf("Month Day Year: ");
    scanf("%d %d %d", &month, &day, &year);

    // Convert the past date to a sparse time struct.
    tm_struct past_in;
    past_in.tm_mon = month - 1;
    past_in.tm_year = (year > 1900 ? year - 1900 : 1900 - year);
    past_in.tm_mday = day;

    // mktime will convert the sparse struct to secs.
    time_t past_secs = mktime(&past_in);
    // Calculate the time difference and convert to days.
    double secs = difftime(now_secs, past_secs);
    int num_days = (int)secs / 3600 / 24;

    // Make a buffer and fill it with the day of the week.
    char day_name[10] = { '\0' };
    tm_struct* past_out = localtime(&past_secs);
    strftime(day_name, 10, "%a", past_out);

    // Results: day of the week and days elapsed to present.
    printf("%s\n%d day(s) ago\n", day_name, num_days);

    // Exit with success.
    return 0;
}
