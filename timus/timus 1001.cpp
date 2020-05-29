#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

typedef long long int li;

int main()
{
    vector<double>sq;
    li a,i,sz;
    double s;
    while(scanf("%lld",&a)!=EOF)
    {
        sq.push_back(sqrt(a));
    }
    sz=sq.size()-1;
    for(i=sz-1;i>=0;i--)
    {
        printf("%.4lf\n",sq[i]);
    }
    return 0;
}
