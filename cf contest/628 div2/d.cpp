#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, i, l, u, m;
    freopen("input.txt","r",stdin);

    scanf("%d", &n);
    int a[n];

    for(i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    scanf("%d", &x);

    l = 0;
    u = n - 1;

    while(1)
    {
        m = l + ceil((u - l) / 2.0);printf("%d\n", m);

        if(a[m] == x) { printf("Match at index: %d\n", m); break; }
        else if(a[m] < x) l = m;
        else u = m;

        //if(m - l == 1 || u - m == 1) { printf("No Match\n"); break; }
    }
    return 0;
}
