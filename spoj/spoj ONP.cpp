#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int main()
{
    char st[500];
    stack<char>x;
    vector<char>ans;
    char priority[1000],temp;
    int i,j,k,t,lenght;

    priority['(']=6;
    priority['^']=5;
    priority['/']=4;
    priority['*']=3;
    priority['-']=2;
    priority['+']=1;

    cin>>t;
    while(t--)
    {
        ans.clear();n
        cin>>st;
        //cout<<st;
        for(i=0;st[i]!='\0';i++)
        {
            //cout<<st[i];
            if(isalpha(st[i]))
                ans.push_back(st[i]);
            else if(st[i]=='(')
            {
                x.push(st[i]);
                //cout<<x.top();
            }

            else if(st[i]==')')
            {
                temp=x.top();
                x.pop();
                while(temp!='(')
                {
                    ans.push_back(temp);
                    //cout<<x.size()<<endl;
                    temp=x.top();
                    x.pop();
                }
            }
            else
            {
                if(x.size()==0)
                    x.push(st[i]);
                else
                {
                    temp=x.top();
                    if((priority[temp]<priority[st[i]]))
                    {
                        ans.push_back(x.top());
                        x.pop();
                        x.push(st[i]);
                    }
                    else
                        x.push(st[i]);
                }

            }
        }
        while(x.size()>0)
        {
            ans.push_back(x.top());
            x.pop();
        }
        lenght=ans.size();
        for(i=0;i<lenght;i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
