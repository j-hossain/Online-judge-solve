#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    string s;
    cin>>s;
    int p,q,x=0;
    for(int i=0; i<m; i++)
    {
        int h;
        int p,q,x=0;
        if(s[i]=='B'&&x==0)
        {
            p=1;
            q=0;
            x=1;
        }
        else if(s[i]=='R'&&x==0)
        {
            p=0;
            q=1;
            x=1;
        }



        if(p==0&&q==1)
        {
            for(int j=i; j<m; j=j+n)
            {

                if(s[j]=='#')
                {
                    cout<<"Oppss!!"<<endl;
                    h=0;
                    break;
                }
                else if(s[j]=='B')
                {
                    cout<<"Yeah!!"<<endl;
                    h=0;
                    break;
                }
                else if(j+n>=m)
                {
                    cout<<"Oppss!!"<<endl;
                    h=0;
                }
            }
        }
        else if(p==1&&q==0)
        {
            for(int j=i; j<m; j=j+n)
            {

                if(s[j]=='#')
                {
                    cout<<"Oppss!!"<<endl;
                    h=0;
                    break;
                }
                else if(s[j]=='R')
                {
                    cout<<"Yeah!!"<<endl;
                    h=0;
                    break;
                }
                else if(j+n>=m)
                {
                    cout<<"Oppss!!"<<endl;
                    h=0;
                    break;
                }
            }
        }
        if(h==0)
        {
            break;
        }



    }




    return 0;





}