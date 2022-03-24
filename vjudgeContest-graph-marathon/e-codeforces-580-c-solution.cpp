/*
    ▀ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▀
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█▀▀▄▄░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▀▀▄░░░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▀▄░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░
    ░░░░░░░░░█░░░░░░░▄▀░░░░░░░░░░░░░
    ░░░░░░░░░█░░░░▄▄▀░░░░░░░░░░░░░░░
    ░░░░░░░░░█▄▄▀▀░░░░JOKER░░░░░░░░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ▄ ░░░░░░░░░░░░░░░░░░░░░░░░░░░░ ▄
*/

#include <iostream>
#include <vector>
using namespace std;

#define MM (int)1e5 + 5

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

int n, m;
int ans;
int cat[MM];
vector<int> grph[MM];

void dfs(int u, int par, int tcat, int flag)
{
    // cout << u << " " << tcat << "\n";
    if (tcat > m)
    {
        flag = 1;
    }

    if (grph[u].size() == 1 and grph[u][0] == par)
    {
        if (!flag)
            ans++;
        return;
    }
    for (auto v : grph[u])
    {
        if (v != par)
        {
            dfs(v, u, cat[v] ? tcat + 1 : 0, flag);
        }
    }
}

int main()
{
    inout();
    int u, v;
    cin >> n >> m;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        grph[u].push_back(v);
        grph[v].push_back(u);
    }
    dfs(1, 0, cat[1], 0);
    cout << ans << "\n";
}