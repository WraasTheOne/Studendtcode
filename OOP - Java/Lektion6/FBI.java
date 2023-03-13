package Lektion6;

import java.util.Scanner;

public class FBI {

    public static void main(String[] args){
        int dum = 0;
        Scanner ob = new Scanner(System.in);
        String[] a = new String[5];
        Boolean[] k = new Boolean[5];

        for (int i = 0; i < 5; i++){
            a[i] = ob.nextLine();
        }
        for (int i = 0; i < 5; i++){
            k[i] = a[i].contains("FBI");
        }

        for (int i = 0; i < 5; i++){
            if(k[i]){
                System.out.println(i+1);
            }else{
                dum +=1;
            }
        }

        if(dum > 4){
            System.out.println("HE GOT AWAY!");
        }

    }
}
