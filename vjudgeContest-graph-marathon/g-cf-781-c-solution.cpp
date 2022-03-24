#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define MM (int)2e5 + 5

int n, m, k, lim, cur;
vector<int> ans[MM];
vector<int> grph[MM];
int vis[MM];

void bfs(int s)
{
    queue<int> qq;
    qq.push(s);
    vis[s] = 1;
    ans[cur].push_back(s);
    if (ans[cur].size() >= lim)
    {
        cur++;
    }

    while (!qq.empty())
    {
        int u = qq.front();
        qq.pop();
        for (auto v : grph[u])
        {
            if (!vis[v])
            {
                ans[cur].push_back(v);
                if (ans[cur].size() >= lim)
                    cur++;
                vis[v] = 1;
                qq.push(v);
            }
        }
    }
}

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

void answer()
{
    int u, v;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        grph[u].push_back(v);
        grph[v].push_back(u);
    }
    cur = 1;
    lim = ceil((2.0 * n) / k);
    bfs(1);

    for (int i = 1; i <= k; i++)
    {
        cout << ans[i].size() << " ";
        for (auto j : ans[i])
        {
            cout << j << " ";
        }
        cout << "\n";
        ans[i].clear();
    }
}

int main()
{
    fast();
    inout();
    answer();
    return 0;
}