package Lektion7;

import java.util.Scanner;

public class Speed {


    public static void main(String[] args){

        Scanner ob = new Scanner(System.in);
        int x = 0;
        while(x != -1){
            int miles = 0, hours = 0;
            int currentM, currentH;
            String[] arr = new String[2];
            for (int i = 0; i < x; i++){
                arr = ob.nextLine().split(" ");
                currentM = Integer.parseInt(arr[0]);
                currentH = Integer.parseInt(arr[1]);
                miles += currentM * (currentH - hours);
                hours = currentH;
            }
            if(x > 0){
                System.out.println(miles + " miles");
            }
            x = Integer.parseInt(ob.nextLine());
        }

    }
}
