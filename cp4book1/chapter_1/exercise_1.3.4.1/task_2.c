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

#include <math.h>
#include <stdio.h>

int
main(int argc, char* argv[])
{
    // Allocate local/stack memory.
    int n = 0;
    // Get integer input.
    scanf("%d", &n);
    // Check n is within range (n <= 15).
    if (n >= 0 && n <= 15)
        printf("%.*f\n", n, M_PI);
    // Exit with success.
    return 0;
}
