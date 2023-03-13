package Lektion7;

import java.awt.*;
import java.util.Scanner;

public class Buttons {


    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // number of button packages in the box
        sc.nextLine(); // consume the newline character
        int counter = 0;

        boolean hasPinkButtons = false;
        for (int i = 0; i < n; i++) {
            String colorName = sc.nextLine().toLowerCase();
            if (colorName.contains("pink") || colorName.contains("rose")) {
                hasPinkButtons = true;
                counter++;

            }
        }

        if (hasPinkButtons) {
            System.out.println(counter);
        } else {
            System.out.println("I must watch Star Wars with my daughter");
        }


        /*public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            int N = scan.nextInt();
            int counter = 0;
            for (int i = 0; i < N; i++) {
                String txt = scan.next();
                txt = txt.toLowerCase();
                if (txt.contains("pink") || txt.contains("rose")) {
                    counter++;
                }
            }
            if (counter > 0) {
                System.out.println(counter);
            } else {
                System.out.println("I must watch Star Wars with my daughter");
            }
        }*/
    }
}
