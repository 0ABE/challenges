// The task specifies to use Java.

import java.util.*;

class Main
{
    public static void main(String[] args)
    {
        // Read in a double.
        double d = new Scanner(System.in).nextDouble();
        // Echo it with a min field width of 7 and 3 decimal places.
        System.out.printf("%7.3f\n", d);
    }
}
