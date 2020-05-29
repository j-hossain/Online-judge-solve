#include<stdio.h>
#include<string.h>

int main()
{
    char strng[100001];
    int i,lenght,cnt1,cnt2,cnt3,cnt4;
    scanf("%s",strng);
    cnt1=cnt2=cnt3=cnt4=0;
    lenght=strlen(strng);

    for(i=0;i<lenght-1;i++)
    {
        if(i<lenght-2 && strng[i]=='B' && strng[i+1]=='A' && strng[i+2]=='B' && !cnt4)
        {
            cnt4=1;
            strng[i]=strng[i+1]=strng[i+2]='X';
        }
        else if(i<lenght-2 && strng[i]=='A' && strng[i+1]=='B' && strng[i+2]=='A' && !cnt1)
        {
            cnt1=1;
            strng[i]=strng[i+1]=strng[i+2]='X';
        }
        else if(strng[i]=='A' && strng[i+1]=='B' && !cnt2)
        {
            cnt2=1;
            strng[i]=strng[i+1]='X';
        }
        else if(strng[i]=='B' && strng[i+1]=='A' && !cnt3)
        {
            cnt3=1;
            strng[i]=strng[i+1]='X';
        }
    }
    //printf("%d %d\n",cnt3,cnt3);
    if((cnt1 && cnt2)||(cnt1 && cnt3)||(cnt4 && cnt2)||(cnt1 && cnt4)||(cnt4 && cnt3)||(cnt2 && cnt3))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
