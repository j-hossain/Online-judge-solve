#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

#define fast()      ios_base::sync_with_stdio(false);cin.tie(NULL);

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("F:/Problem Solving/Online judges/input.txt","r",stdin);
    freopen("F:/Problem Solving/Online judges/output.txt","w",stdout);
    #endif
}

char uni[5005][205];

int exists(int n, char word[]){

    int i;
    for(i=0;i<n;i++){
        if(!strcmp(uni[i],word))
            return 1;
    }
    return 0;
}

void bringWord(char *word){

    int i;
    char res[205];
    int j=0;
    for(i=0;word[i]!='\0';i++)
    {
        if(isalpha(word[i]))
        {
            word[i]=tolower(word[i]);
            res[j++]=word[i];
        }
    }
    res[j++]='\0';

    for(i=0;i<=j;i++)
        word[i]=res[i];
}

void sortUni(int n){

    int i,j,p;
    char temp[205];
    for(i=0;i<n-1;i++)
    {
        p=i;
        for(j=i+1;j<n;j++)
        {
            if(strcmp(uni[p],uni[j])>0)
                p=j;
        }
        if(p!=i)
        {
            strcpy(temp,uni[i]);
            strcpy(uni[i],uni[p]);
            strcpy(uni[p],temp);
        }
    }
}


int main(){

    inout();

    int n,i,len,l;
    char word[205],letter;
    string line;
    n=i=0;
    while(getline(cin,line)){

        int lnLen = line.length();
        l=0;
        while(l<lnLen){

            letter=line[l++];
            if(isalpha(letter) && letter!=' ')
                word[i++]=letter;
            else if(i>0){
                word[i]='\0';
                i=0;
                bringWord(word);
                len = strlen(word);
                if(!exists(n,word) && len){
                    strcpy(uni[n++],word);
                }
            }
        }
        if(i>0){
            word[i]='\0';
            i=0;
            bringWord(word);
            len = strlen(word);
            if(!exists(n,word) && len){
                strcpy(uni[n++],word);
            }
        }
    }
    sortUni(n);
    for(i=0;i<n;i++)
        cout<<uni[i]<<endl;

    return 0;
}
