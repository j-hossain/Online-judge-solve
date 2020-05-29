#include<stdio.h>
#include<string.h>

int main()
{
    char team1[11],team2[11],temp[11];
    int goal1,goal2,i,n,flag;

    goal1=goal2=0;
    flag=0;

    scanf("%d",&n);
    scanf("%s",team1);

    goal1++;

    for(i=1;i<n;i++)
    {
        scanf("%s",temp);
        if(!strcmp(temp,team1))
            goal1++;
        else if(!flag)
        {
            strcpy(team2,temp);
            goal2++;
            flag=1;
        }
        else
            goal2++;
    }
    if(goal1>goal2)
        printf("%s\n",team1);
    else
        printf("%s\n",team2);
    return 0;
}
