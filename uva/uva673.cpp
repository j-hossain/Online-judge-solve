#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int i,n,cnt1,cnt2,flag;
    stack<char>check;
    char st[130];
    //freopen("output.txt","w+",stdout);
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        flag=0;
        while(!check.empty())
            check.pop();

        gets(st);
        for(i=0;st[i]!='\0';i++)
        {
            if(st[i]=='[' || st[i]=='(')
                check.push(st[i]);
            else if(!check.empty())
            {
                if((st[i]==')' && check.top()!='(')||(st[i]==']' && check.top()!='['))
                {
                    flag=1;
                    break;
                }
                check.pop();
            }
            else if(st[i]==')'|| st[i]==']')
            {
                flag=1;
                break;
            }
        }
        if(!flag && check.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
