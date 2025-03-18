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

import java.math.BigInteger;
import java.util.*;

class Main
{
    public static void main(String[] args)
    {
        @SuppressWarnings("resource")
        Scanner scan = new Scanner(System.in);
        System.out.printf("from base: ");
        int from = scan.nextInt();
        System.out.printf("value in base %d: ", from);
        String value = scan.next();
        System.out.printf("to base: ");
        int to = scan.nextInt();
        BigInteger bin = new BigInteger(value, from);
        System.out.printf("value in base %d: %s\n", to, bin.toString(to));
    }
}
