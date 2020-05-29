#include<stdio.h>
#include<string.h>

int main()
{
    char s1[100001],s2[100001],l1,l2;
    scanf("%s",s1);
    scanf("%s",s2);
    if(!strcmp(s1,s2))
    {
        printf("-1\n");
        return 0;
    }
    else
        printf("%d\n",strlen(s1)>strlen(s2)?strlen(s1):strlen(s2));
    return 0;
}
