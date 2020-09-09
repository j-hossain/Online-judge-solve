#include<iostream>
using namespace std;

int main()
{
    int len,flag=0,i,j;
    char grid[300][300],diagonal,other;

    cin>>len;
    //taking the grid input
    for(i=0;i<len;i++)
    {
        cin>>grid[i];
    }
    diagonal = grid[0][0];
    //checking the diagonal letters3
    for(i=0;i<len;i++)
    {
        if(!(grid[i][i]==diagonal && grid[i][i]==grid[i][len-1-i]))
            break;
        else
        {
            grid[i][i]=grid[i][len-1-i]='.';
        }

    }

    if(i==len)//the loop never broke by the condition
    {
        //now check the other letters
        other = grid[0][1];
        for(i=0;i<len;i++)
        {
            for(j=0;j<len;j++)
            {
                if(grid[i][j]!='.' && grid[i][j]!=other)
                    break;
            }
            if(j<len)
                break;
        }
        if(i==len)
            flag=1;
    }

    if(flag && diagonal!=other)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
