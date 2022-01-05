#include <stdio.h>
#include <math.h>

typedef long long int ll;

int main()
{
    ll n, m, t, i, j, sq;
    int mark[100001];
    scanf("%lld", &t);
    while (t--)
    {
        i = 0;
        while (i < 100001)
        {
            mark[i++] = 0;
        }

        scanf("%lld %lld", &m, &n);
        sq = sqrt(n);
        if (m == 1)
            mark[0] = 1;
        for (i = (m + (m % 2)); i <= n; i += 2)
        {
            mark[i - m] = 1;
        }
        for (i = 3; i <= sq; i += 2)
        {
            for (j = i * i; j <= n; j += (i * 2))
            {
                if (j >= m)
                    mark[j - m] = 1;
            }
        }
        if (m <= 2)
            printf("2\n");
        for (i = 0; i < (n - m + 1); i++)
        {
            if (!mark[i])
                printf("%lld\n", i + m);
        }
        printf("\n");
    }
    return 0;
}
