import java.util.*;

public class cf_1554_A_Cherry{
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        long t,n,mx,mul;
        long arr[] = new long[200005];

        t = inp.nextInt();
        while(t>0){
            t--;
            n = inp.nextInt();
            for(int i=0;i<n;i++){
                arr[i]=inp.nextInt();
            }
            mx = 0;
            for(int i=1;i<n;i++){
                mul = arr[i]*arr[i-1];
                mx = Long.max(mx, mul);
            }
            System.out.println(mx);
        }
    }
}