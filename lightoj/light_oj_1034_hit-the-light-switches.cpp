#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<int> grph[50001];
vector<int> current;
int vis[10005];
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

void bfs(int s)
{
    vis[s] = 1;
    for (int i = 0; i < grph[s].size(); i++)
    {
        int d = grph[s][i];
        if (!vis[d])
        {
            bfs(d);
        }
    }
    current.push_back(s);
}

void dfs(int s)
{
    vis[s] = 1;
    for (int i = 0; i < grph[s].size(); i++)
    {
        int d = grph[s][i];
        if (!vis[d])
        {
            dfs(d);
        }
    }
}

int main()
{
    fast();
    inout();
    int t, n, m, u, v, tt, ans;
    cin >> t;
    tt = 1;
    while (t--)
    {
        cout << "Case " << tt << ": ";
        tt++;
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            grph[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            grph[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                bfs(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
        }
        while (!current.empty())
        {
            int i = current.back();
            current.pop_back();
            if (!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        cout << ans << "\n";
    }
}