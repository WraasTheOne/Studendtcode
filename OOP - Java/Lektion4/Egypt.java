package Lektion4;

import java.util.Scanner;

public class Egypt {
    public static void main(String[] args){
        Scanner skanner = new Scanner(System.in);

        int a = 1, b = 1, c = 1, swap;

        while (a != 0 && b != 0 && c != 0){
            String line = skanner.nextLine();
            String[] ab = line.split(" ");
             a = Integer.parseInt(ab[0]);
             b = Integer.parseInt(ab[1]);;
            c = Integer.parseInt(ab[2]);;

            if (c < a || c < b){
                if(c < a && c >= b){
                    swap = c;
                    c = a;
                    a = swap;
                }else{
                    swap = c;
                    c = b;
                    b = swap;
                }
            }

            double resultat = Math.pow(a,2) + Math.pow(b,2);

            if(Math.pow(c,2) == resultat){
                System.out.println("right");
            }else{
                System.out.println("wrong");
            }
        }
    }
}
