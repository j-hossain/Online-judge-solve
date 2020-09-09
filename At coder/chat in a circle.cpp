#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,arr[200005],mn,i,j;

    long long int sum;

    sum=0LL;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    sum+=arr[n-1];
    j=2;
    for(i=n-2;i>=0 && j<n ;i--)
    {
        j++;
        sum+=arr[i];
        if(j<n)
        {
            j++;
            sum+=arr[i];
        }
    }

    cout<<sum<<endl;
    return 0;
}
