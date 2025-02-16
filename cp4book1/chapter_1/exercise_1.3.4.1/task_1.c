// The task specifies to use java (see task_1.java).
// Duplicated here in C.

#include <stdio.h>

int
main(int argc, char* argv[])
{
    // Allocate local/stack memory.
    double d = 0;
    // Read in a double.
    scanf("%lf", &d);
    // Echo it with a min field width of 7 and 3 decimals.
    printf("%7.3f\n", d);
    // Exit with success.
    return 0;
}
