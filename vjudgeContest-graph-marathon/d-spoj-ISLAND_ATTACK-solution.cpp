#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

// for faster cin cout
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int n, m, saved;
char grph[105][105];
int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
// int dj[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool valid(int i, int j)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return false;
    if (grph[i][j] == '.')
        return false;
    return true;
}

void checkIland(int i, int j)
{
    int pep = 0;
    int shel = 0;
    int x, y;
    queue<pair<int, int>> qq;
    qq.push({i, j});
    if (grph[i][j] == 'H')
    {
        pep++;
    }
    else if (grph[i][j] != '#')
    {
        shel += grph[i][j] - '0';
    }
    grph[i][j] = '.';
    while (!qq.empty())
    {
        tie(x, y) = qq.front();
        qq.pop();
        for (int k = 0; k < 4; k++)
        {
            if (valid(x + di[k], y + dj[k]))
            {
                if (grph[x + di[k]][y + dj[k]] == 'H')
                {
                    pep++;
                }
                else if (grph[x + di[k]][y + dj[k]] != '#')
                {
                    shel += grph[x + di[k]][y + dj[k]] - '0';
                }
                grph[x + di[k]][y + dj[k]] = '.';
                qq.push({x + di[k], y + dj[k]});
            }
        }
    }
    int rem = pep - shel < 0 ? 0 : pep - shel;
    if (rem > pep / 2)
    {
        rem = pep;
    }
    saved += (pep - rem);
}

void answer()
{
    saved = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grph[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grph[i][j] != '.')
            {
                checkIland(i, j);
            }
        }
    }
    if (!saved)
    {
        cout << "is no survivor.\n";
    }
    else if (saved == 1)
    {
        cout << "is 1 survivor.\n";
    }
    else
    {
        cout << "are " << saved << " survivors.\n";
    }
}

int main()
{
    fast();
    // inout();
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": There ";
        answer();
    }
}