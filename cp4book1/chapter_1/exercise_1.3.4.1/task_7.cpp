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

#include <algorithm>
#include <stdio.h>

int
main(int argc, char* argv[])
{
    // Shorten the buffer for testing/speedup.
    char buf[] = "ABCDEFGHIJ";
    const int n = sizeof(buf) / sizeof(char) - 1;

    // Output the length of the buffer at the top.
    printf("size: %d\n\n", n);

    // Print out the permutation number on each line.
    long np = 0;
    // Output the given original permutation.
    printf("%7ld. %s\n", ++np, buf);

    // Raw pointers work as bidirectional and random access iterators.
    char* begin_iter = buf;
    char* end_iter = buf + n;

    // Find the rest of the permutations of the buffer.
    while (std::next_permutation(begin_iter, end_iter)) {
        printf("%7ld. %s\n", ++np, buf);
    }

    return EXIT_SUCCESS;
}
