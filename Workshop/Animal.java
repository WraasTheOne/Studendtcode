public class Animal implements Feed {
    protected int id;

    protected boolean isSick;

    protected String diet;

    public int getId(Animal ob){
        return ob.id;
    }

    public boolean isSick(Animal ob){
        return ob.isSick;
    }

    public void setSick(Animal ob){
        ob.isSick = true;
    }

    public void feed(){
        System.out.println("Feed");
    }

    public void getDiet(){
        System.out.println("Diet");
    }



}
