#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
// accepted

#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int lcsGrid[105][105];
map<int, map<int, string>> dp;
string sts;

void generateLcsGrid(string a, string b)
{
    int n = a.size();
    int m = b.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                lcsGrid[i][j] = 0;
                dp[i][j] = "";
            }
            else if (a[i - 1] == b[j - 1])
            {
                lcsGrid[i][j] = 1 + lcsGrid[i - 1][j - 1];
                dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
            }
            else
            {
                lcsGrid[i][j] = max(lcsGrid[i - 1][j], lcsGrid[i][j - 1]);
                if (lcsGrid[i - 1][j] > lcsGrid[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (lcsGrid[i - 1][j] < lcsGrid[i][j - 1])
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void solve()
{
    string a, b;
    cin >> a >> b;
    generateLcsGrid(a, b);
    if (dp[a.size()][b.size()].size() > 0)
    {
        cout << dp[a.size()][b.size()] << "\n";
    }

    else
    {
        cout << ":(\n";
    }
}

int main()
{
    fast();
    inout();
    int t, tc = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << tc << ": ";
        solve();
        tc++;
        dp.clear();
    }
}