#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    char s;
    string st;
    vector<int>arr;
    int i,u,v,num,query,zero='0',tk;
    tk=0;
    while(cin>>st)
    {
        tk++;
        arr.clear();

        printf("Case %d:\n",tk);
        arr.push_back(st[0]-zero);
        for(i=1;i<st.size();i++)
        {
            arr.push_back(arr[i-1]+st[i]-zero);
        }
        scanf("%d",&query);
        for(i=0;i<query;i++)
        {
            scanf("%d %d",&u,&v);
            if((arr[v]-arr[u]==v-u || arr[v]==arr[u]) && st[u]==st[v])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
