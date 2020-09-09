#include<iostream>
using namespace std;

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);


int main()
{
    int n,arr[1005],i,pr,nx,j,flag;

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>arr[i];

        for(i=1;i<n;i++)
        {
            pr=nx=-1;

            for(j=i-1;j>=0;j--)
            {
                if(arr[i]>arr[j])
                {
                    pr=j;
                    break;
                }
            }
            for(j=i+1;j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    nx=j;
                    break;
                }
            }

            if(pr!=-1 && nx!=-1)
                break;
        }

        if(pr!=-1 && nx!=-1)
        {
            cout<<"YES\n";
            cout<<(pr+1)<<" "<<(i+1)<<" "<<(nx+1)<<endl;
        }
        else
            cout<<"NO\n";
    }
}
