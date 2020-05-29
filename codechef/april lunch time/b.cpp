#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int arr[100005],b[100005];
    vector<int>p;
    vector<int>q;
    int i,j,n,k,tk;
    scanf("%d",&tk);
    while(tk--)
    {
        scanf("%d %d",&n,&k);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
            b[i]=arr[i];
        }
        sort(&b[0],&b[n+1]);

        for(i=1; i<=k; i++)
        {
            p.clear();
            q.clear();
            for(j=i;j<=n;j+=k)
            {
                p.push_back(arr[j]);
                q.push_back(b[j]);
            }
            sort(p.begin(),p.end());

            if(p!=q)
                break;
        }
        if(i<=k)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
