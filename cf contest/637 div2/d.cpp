#include<stdio.h>
#include<vector>
#include<iostream>
#include<string.h>

using namespace std;

int need(char d1[],char d2[])
{
    int s1,s2;
    s1=s2=0;
    for(int i=0;i<7;i++)
    {
        s1+=(d1[i]-'0');
        s2+=(d2[i]-'0');
    }
    return s1-s2;
}

int same(char d1[],char d2[])
{
    int i;
    for(i=0;i<7;i++)
    {
        if(d1[i]=='0')
        {
            if(d2[i]!='0')
                break;
        }
    }
    if(i<7)
        return 0;
    else
        return 1;
}

typedef struct
{
    int dig;
    int needk;
}psbl;

int possible[2005][10];

int main()
{
    char digits[10][8];
    char onboard[8];
    int get;
    int n,k,i,j,v;

    strcpy(digits[0],"1110111");
    strcpy(digits[1],"0010010");
    strcpy(digits[2],"1011101");
    strcpy(digits[3],"1011011");
    strcpy(digits[4],"0111010");
    strcpy(digits[5],"1101011");
    strcpy(digits[6],"1101111");
    strcpy(digits[7],"1010010");
    strcpy(digits[8],"1111111");
    strcpy(digits[9],"1111011");

    scanf("%d %d",&n,&k);
    for(i=0,v=0;i<n;i++)
    {
        scanf("%s",onboard);
        for(j=9;j>=0;j--)
        {
            possible[i][j]=0;
            if(same(digits[j],onboard)&& need(digits[j],onboard)<=k)
            {
                possible[i][j]=k;
            }
        }
    }
    int get
}

