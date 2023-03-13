package Lektion5;


public class Point {
    int x;

    int y;

    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public Point(){
        x = 0;
        y = 0;
    }

    public double distance(int x, int y){
        return (Math.sqrt(Math.pow(this.x - x,2)+ Math.pow(this.y - y, 2)));
    }

    public String toString(){
        String k = "(" + x + ","+ y +")";
        return k;
    }


}
