#include<stdio.h>
#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int>s;
    int n,i,t,temp,flag;
    int arr[200005];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        s.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        for(i=1;i<=n;i++)
        {
            temp=i+arr[i];
            temp=((temp%n)+n)%n;
            s.insert(temp);
        }
        if(s.size()==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
