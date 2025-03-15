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
 *
 * Subsets corresponds with bitset logic.
 * Members of a subset are represented by a 1 in a bit string.
 * If a buffer is filled with consecutively increasing numbers
 * then subset (1 3 4) is represented by 1101.
 */

#include <stdio.h>

// There are 2^n - 1 subsets.
//   n |       2^n |   subsets
// ----------------------------
//   2 |         4 |         3
//   3 |         8 |         7
//   4 |        16 |        15
//   5 |        32 |        31
//  .. |        .. |        ..
//  20 | 1,048,576 | 1,048,575
const static int n = 5;

int
main(int argc, char* argv[])
{
    // Fill the buffer with numbers 1 to n...
    int buf[n] = { 0 };
    for (int i = 0; i < n; ++i) {
        buf[i] = i + 1;
        // and print it out.
        printf("%d ", buf[i]);
    }
    printf("\n\n");

    // Init the subset counter.
    int ns = 0;

    // Loop up to 2^n, starting with 1. There is no need for i
    // to start at 0 since (0 & x) is always 0.
    for (int i = 1; i < (1 << n); ++i) {
        printf("%d. ", ++ns);
        for (int j = 0; j < n; ++j)
            // j is the positional index into the buffer.
            if (i & (1 << j))
                printf("%d ", buf[j]);

        printf("\n");
    }

    return 0;
}
