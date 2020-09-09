#include<iostream>
using namespace std;

int main()
{
    int num[3],t;
    cin>>t;
    while(t--)
    {
        cin>>num[0]>>num[1]>>num[2];

        for(int i=0;i<2;i++)
            for(int j=i+1;j<3;j++)
            {
                if(num[i]<num[j])
                {
                    num[i]=num[i]+num[j];
                    num[j]=num[i]-num[j];
                    num[i]=num[i]-num[j];
                }
            }
        if(num[0]==num[1])
        {
            cout<<"YES"<<endl;
            cout<<num[0]<<" "<<num[2]<<" "<<num[2]<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
