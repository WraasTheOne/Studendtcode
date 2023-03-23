package Lektion7;

import java.util.Scanner;

public class Server {
    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in);
        int numDrives = ob.nextInt();
        int MaxMin = ob.nextInt();
        int counter = 0;
        int drive = 0;

        for (int i = 0; i < numDrives; i++){
            drive = ob.nextInt();
            MaxMin -= drive;

            if(MaxMin >= 0){
                counter ++;
            }
        }

        System.out.println(counter);


        //System.out.println(numDrives + " " + MaxMin);



    }


}
