#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("C:/Jahin/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("C:/Jahin/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

int main(){
    inout();
    char inp;
    int x = 1;
    int flag=0;
    while(scanf("%c",&inp)!=EOF){
        // if(flag)
        //     printf("")
        // flag=1;
        if(inp=='"'){
            if(x)
                printf("``");
            else
                printf("''");
            x^=1;
        }
        else
            printf("%c",inp);
    }
    return 0;
}