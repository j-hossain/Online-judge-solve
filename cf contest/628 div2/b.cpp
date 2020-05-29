#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int>a;
    int n,i,tk,arr;
    scanf("%d",&tk);
    while(tk--)
    {
        a.clear();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&i);
            a.insert(i);
        }
        printf("%d\n",a.size());
    }
    return 0;
}
