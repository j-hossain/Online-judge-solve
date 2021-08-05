import java.util.Scanner;

public class testing {
    
    public static void main(String []a){
        Scanner sc = new Scanner(System.in);
        double maxim = 0.0;
        double mini = 0.0;
        double sec = 0.0;
        double temp;
        double aver;
        double sum=0.0;
        double cnt;
        
        cnt = sc.nextDouble();

        for(int i=0;i<cnt;i++){
            temp = sc.nextDouble();
            sum+=temp;

            if(temp>maxim){
                maxim = temp;
            }
            else if(temp>sec)
                sec = temp;
            if(temp<mini || mini==0.0)
                mini = temp;
        }
        aver = sum/cnt;
        System.out.println("The highest value: " + maxim);
        System.out.println("The lowest value: " + mini);
        System.out.println("The lowest value: " + aver);
        System.out.println("The second highest value: " + sec);
    }
}
