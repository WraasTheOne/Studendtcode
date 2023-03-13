package Lektion6;

import java.util.Scanner;

public class Maiin {
    public static void main(String[] args){
        Scanner ob = new Scanner(System.in);
        int x = 0;
        int a = Integer.parseInt(ob.nextLine());
        int b = Integer.parseInt(ob.nextLine());
        int[] c = new int[b];
        for (int i = 0; i < b; i++){
            c[i] = Integer.parseInt(ob.nextLine());
        }

        for (int i = 0; i < b; i++){
            x = (a+x)-c[i];
        }
        System.out.println(x+a);

    }
}
