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
 * The task specifies to use Java (see task_1.java).
 */

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
