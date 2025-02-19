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
#include <stdlib.h>
#include <time.h>

// Function pointer type
typedef int (*compare_fn)(const void*, const void*);

int
compare_asc(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int
compare_desc(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

// My own version of qsort, for fun of course.
// - stdlib qsort runs about twice as fast as abe_qsort.
void
abe_qsort(int* nums, int len, size_t type_size, compare_fn compare)
{
    // Guard against nothing to do.
    if (len == 1)
        return;

    // Check for a possible swap.
    if (len == 2) {
        if (compare(&nums[0], &nums[1]) > 0) {
            int t = nums[0];
            nums[0] = nums[1];
            nums[1] = t;
        }
        return;
    }

    // By tradition, take the pivot as the last int.
    int pivot = nums[len - 1];

    // Count up the size for each array.
    int nbeg, nmid, nend;
    nbeg = nmid = nend = 0;
    for (int i = 0; i < len; ++i)
        if (compare(&nums[i], &pivot) < 0)
            nbeg++;
        else if (compare(&nums[i], &pivot) == 0)
            nmid++;
        else
            nend++;

    // Allocate memory for beg, mid, and end arrays.
    int* beg = malloc(nbeg * type_size);
    int* mid = malloc(nmid * type_size);
    int* end = malloc(nend * type_size);

    // Classify as beg, mid (pivot), or end compared to the pivot.
    int ibeg, imid, iend;
    ibeg = imid = iend = 0;
    for (int i = 0; i < len; ++i)
        if (compare(&nums[i], &pivot) < 0)
            beg[ibeg++] = nums[i];
        else if (nums[i] == pivot)
            mid[imid++] = nums[i];
        else
            end[iend++] = nums[i];

    // Recursively sort beg and end arrays.
    // mid contains values the same as the pivot.
    if (nbeg > 1)
        abe_qsort(beg, nbeg, type_size, compare);
    if (nend > 1)
        abe_qsort(end, nend, type_size, compare);

    // Concatenate: overwrite [beg, mid, end] into nums.
    int i = 0;
    if (nbeg > 0)
        for (; i < nbeg; ++i)
            nums[i] = beg[i];
    if (imid > 0)
        for (int j = 0; i < nbeg + nmid; ++i, ++j)
            nums[i] = mid[j];
    if (iend > 0)
        for (int j = 0; i < nbeg + nmid + nend; ++i, ++j)
            nums[i] = end[j];

    // If memory was allocated, free it.
    if (nbeg > 0)
        free(beg);
    if (nmid > 0)
        free(mid);
    if (nend > 0)
        free(end);
}

int
main(int argc, char* argv[])
{
    // Seed the random number generator with current time.
    srand(time(NULL));
    // Get the number of random ints to generate.
    // Enter more than 10 to guarantee duplicates.
    int n = 0;
    scanf("%d", &n);

    // Allocate space for n ints and fill it.
    int* nums = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        nums[i] = (rand() % 10) + 1; // 1 --> 10
        //  Print the array of random numbers.
        printf("%d ", nums[i]);
        if (i == n - 1)
            printf("\n");
    }

    clock_t clock_time;
    clock_time = clock();

    // Sort the array with a custom qsort function.
    abe_qsort(nums, n, sizeof(int), compare_asc);
    
    // Use qsort from the stdlib (twice as fast as mine!)
    // qsort(nums, n, sizeof(int), compare_asc);

    clock_time = clock() - clock_time;
    const double total_time = ((double) clock_time)/CLOCKS_PER_SEC;

    // Print the unique ints in the array.
    for (int i = 0, j = 1; j < n; ++i, ++j) {
        if (nums[i] != nums[j])
            printf("%d ", nums[i]);
        if (j == n - 1) {
            printf("%d", nums[j]);
            printf("\n");
        }
    }

    free(nums);

    printf("Sorting took %f secs\n", total_time);

    // Exit with success.
    return 0;
}
