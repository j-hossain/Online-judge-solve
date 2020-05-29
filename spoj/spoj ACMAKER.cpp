#include<stdio.h>
#include<string.h>

#define mx 151
#define li long long int

char abbr[mx],words[mx][mx],insig[mx][mx],inp[mx];
int in,sn,aLenght,l[mx],lc[mx];
li dp[mx][mx];

void dpInit()
{
    int i,j;
    for(i=0;i<mx;i++)
    {
        for(j=0;j<mx;j++)
        {
            dp[i][j]=-1LL;
        }
    }
}

void tolow()
{
    int i;
    for(i=0;i<aLenght;i++)
        abbr[i]+=32;
}

int check(char cc[])
{
    int i;
    for(i=0;i<in;i++)
    {
        if(!strcmp(cc,insig[i]))
            return 0;
    }
    return 1;
}

void separate()
{
    int i,j,lenght;
    char temp[mx];
    lenght=strlen(inp);

    for(i=0,j=0;i<=lenght;i++)
    {
        if(inp[i]==' ' || inp[i]=='\0')
        {
            temp[j]='\0';
            if(check(temp))
            {
                l[sn]=strlen(temp);
                if(sn>0)
                    lc[sn]=l[sn-1]+lc[sn-1];

                strcpy(words[sn++],temp);
            }
            j=0;
        }
        else
            temp[j++]=inp[i];
    }
}

li run(int abbrPos, int word, int wordPos)
{
    li cnt=0LL;

    int totalPos=lc[word]+wordPos;

    if(abbrPos==aLenght)
    {
        if(word==sn)
            return 1;
        return 0;
    }
                     //ACCEPTED
    if(word==sn)
        return 0;


    if(dp[totalPos][abbrPos]!=-1)
        return dp[totalPos][abbrPos];

    for(int i=wordPos;i<l[word];i++)
    {
        if(words[word][i]==abbr[abbrPos])
        {
            if(i!=l[word]-1)
                cnt+=run(abbrPos+1,word,i+1);
            cnt+=run(abbrPos+1,word+1,0);
        }
    }
    dp[totalPos][abbrPos]=cnt;
    return dp[totalPos][abbrPos];
}

int main()
{
    int i;
    li ans;
    while(scanf("%d",&in) && in)
    {
        for(i=0;i<in;i++)
            scanf("%s",insig[i]);
        while(1)
        {
            dpInit();
            ans=0LL;
            lc[0]=0;
            sn=0;
            scanf("%s",abbr);
            getchar();
            gets(inp);

            if(!strcmp(abbr,"LAST") && !strcmp(inp,"CASE"))
                break;

            printf("%s",abbr);
            aLenght=strlen(abbr);
            tolow();
            separate();
            ans=run(0,0,0);


            if(ans>0)
                printf(" can be formed in %lld ways\n",ans);
            else
                printf(" is not a valid abbreviation\n");
        }
    }
    return 0;
}
