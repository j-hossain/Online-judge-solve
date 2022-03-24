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

// including all header files
#include <iostream>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

// runs test cases
#define test() \
    int TT;    \
    cin >> TT; \
    for (int TK = 1; TK <= TT; TK++)

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

int n, m;
char grph[105][105];
int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, -1, -1, -1, 0, 1, 1, 1};

int valid(int i, int j)
{
    if (i < 0 or j < 0 or i >= n or j >= m)
        return 0;
    if (grph[i][j] != '@')
        return 0;
    return 1;
}

void bfs(int i, int j)
{
    int x, y;
    queue<pair<int, int>> qq;
    qq.push({i, j});
    while (!qq.empty())
    {
        tie(x, y) = qq.front();
        qq.pop();
        grph[x][y] = '*';
        for (i = 0; i < 8; i++)
        {
            if (valid(x + di[i], y + dj[i]))
            {
                qq.push({x + di[i], y + dj[i]});
                grph[x + di[i]][y + dj[i]] = '*';
            }
        }
    }
}

void answer()
{
    int cnt = 0;
    while (cin >> n >> m)
    {
        cnt = 0;
        if (!n and !m)
        {
            break;
        }
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
                if (grph[i][j] == '@')
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    // fast();
    // inout();
    // t_start;
    // for no test case
    answer();

    // when test cases exist
    // test()
    // {
    //     // pcs;
    //     answer();
    // }
    // t_show;

    return 0;
}
