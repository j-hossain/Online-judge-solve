#include<iostream>
#include<cmath>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

int arr[50],k;

void printComb(int taken){
    int cnt=0;
    for(int i=0;i<k;i++){
        int temp = pow(2,i);
        if(taken&temp){
            cnt++;
            cout<<arr[i];
            if(cnt<6)
                cout<<" ";
        }
    }
    cout<<endl;
}

void getComb(int taken, int cnt,int now){
    if(cnt==6){
        printComb(taken);
        return;
    }

    if(now>=k){
        return;
    }
    int temp = pow(2,now);
    getComb(taken|temp,cnt+1,now+1);
    getComb(taken,cnt,now+1);

}

int main(){

    inout();
    while(cin>>k && k){
        for(int i=0;i<k;i++)
            cin>>arr[i];

        getComb(0,0,0);
    }

}
