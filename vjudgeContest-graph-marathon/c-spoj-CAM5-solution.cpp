#include <iostream>
#include <vector>
using namespace std;

#define MM (int)1e6 + 5

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

vector<int> grph[MM];
int vis[MM];

void dfs(int s)
{
    for (auto v : grph[s])
    {
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
    }
}

void answer()
{
    int n, m, u, v, cnt = 0;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        grph[u].push_back(v);
        grph[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
            4
        }
    }
    for (int i = 0; i < n; i++)
    {
        grph[i].clear();
        vis[i] = 0;
    }
    cout << cnt << "\n";
}

int main()
{
    // inout();
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        answer();
    }
    return 0;
}