// including all header files
#include <bits/stdc++.h>

//<for policy based data structure>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//</for policy based data structure>

using namespace std;

// <for runtime show>
using namespace std::chrono;

#define t_start auto start = high_resolution_clock::now();
#ifndef ONLINE_JUDGE
#define t_show                                                 \
    auto stop = high_resolution_clock::now();                  \
    auto duration = duration_cast<milliseconds>(stop - start); \
    cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
#else
#define t_show
#endif
// </for runtime show>

//<shortcut macros>
#define li long long int
#define uli unsigned long long int

// most used numbers
const int MM = 1e5 + 3;
const int MD = 1e9 + 7;
const double PI = acos(0);

// direction array
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

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

// outputs simplified
#define pcs cout << "Case " << TK << ": "
#define SS ' '
#define NN '\n'

// template declarations simplified
#define pii pair<int, int>
#define pll pair<li, li>
#define MP(a, b) make_pair(a, b)
#define PP push_back
#define ALL(x) x.begin(), x.end()

// for segmentation
#define left st, (st + en) / 2, nd * 2
#define right (st + en) / 2 + 1, en, nd * 2 + 1
//</shortcut macros>

// ordered set
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// for file input output
void inline inout()
{
#ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt", "r", stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt", "w", stdout);
#endif
}

struct pos{
    int i[3];
    int j[3];
};

pos st,cur,en;
queue<pos> qq;

int vis[10][10][10][10][10][10];
int dis[10][10][10][10][10][10];
char g[10][10];
int n;

void precalc(){
}

pos changeAll(pos a, int dd){
    for(int i=0;i<3;i++){
        int ii = a.i[i]+dx[dd];
        int jj = a.j[i]+dy[dd];
        if(ii>=0 and ii<n and jj>=0 and jj<n and g[ii][jj]!='#'){
            a.i[i] = ii;
            a.j[i] = jj;
        }
    }
    return a;
}

pos changeOne(pos a, int dd, int i){
    int ii = a.i[i]+dx[dd];
    int jj = a.j[i]+dy[dd];
    if(ii>=0 and ii<n and jj>=0 and jj<n and g[ii][jj]!='#'){
        a.i[i] = ii;
        a.j[i] = jj;
    }
    return a;
}

void printPos(pos a){
    for(int i=0;i<3;i++) cout<<a.i[i]<<SS<<a.j[i]<<SS;
    cout<<NN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int f=0;
            for(int k=0;k<3;k++){
                if(i==a.i[k] and j==a.j[k]){
                    char x = 'A'+k;
                    cout<<x;
                    f=1;
                    // break;
                }
            }
            if(!f){
                if(g[i][j]=='#') cout<<"#";
                else if(g[i][j]=='X') cout<<"X";
                else cout<<".";
            }
        }
        cout<<"\n";
    }
    cout<<"---\n";
}

void visit(pos a){
    // printPos(a);
    vis[a.i[0]][a.j[0]][a.i[1]][a.j[1]][a.i[2]][a.j[2]]=1;
}

void setDis(pos a, int di){
    dis[a.i[0]][a.j[0]][a.i[1]][a.j[1]][a.i[2]][a.j[2]] = di;
}

int getDis(pos a){
    return dis[a.i[0]][a.j[0]][a.i[1]][a.j[1]][a.i[2]][a.j[2]];
}

bool valid(pos a){
    if(vis[a.i[0]][a.j[0]][a.i[1]][a.j[1]][a.i[2]][a.j[2]]) return 0;
    return 1;
}

bool over(pos a, pos b){
    if(a.i[0]==b.i[0] and a.j[0]==b.j[0]){
        if(a.i[1]==b.i[1] and a.j[1]==b.j[1]){
            if(a.i[2]==b.i[2] and a.j[2]==b.j[2]) return 1;
        }
        else if(a.i[1]==b.i[2] and a.j[1]==b.j[2]){
            if(a.i[2]==b.i[1] and a.j[2]==b.j[1]) return 1;
        }
    }
    else if(a.i[0]==b.i[1] and a.j[0]==b.j[1]){
        if(a.i[1]==b.i[0] and a.j[1]==b.j[0]){
            if(a.i[2]==b.i[2] and a.j[2]==b.j[2]) return 1;
        }
        else if(a.i[1]==b.i[2] and a.j[1]==b.j[2]){
            if(a.i[2]==b.i[0] and a.j[2]==b.j[0]) return 1;
        }
    }
    else if(a.i[0]==b.i[2] and a.j[0]==b.j[2]){
        if(a.i[1]==b.i[1] and a.j[1]==b.j[1]){
            if(a.i[2]==b.i[0] and a.j[2]==b.j[0]) return 1;
        }
        else if(a.i[1]==b.i[0] and a.j[1]==b.j[0]){
            if(a.i[2]==b.i[1] and a.j[2]==b.j[1]) return 1;
        }
    }
    return 0;
}

bool visited(pos a){
    if((a.i[0]==a.i[1] and a.j[0]==a.j[1]) or (a.i[0]==a.i[2] and a.j[0]==a.j[2]) or (a.i[2]==a.i[1] and a.j[2]==a.j[1])) return 1;
    return vis[a.i[0]][a.j[0]][a.i[1]][a.j[1]][a.i[2]][a.j[2]];
}

void answer()
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            if(g[i][j]=='X'){
                en.i[cnt]=i;
                en.j[cnt]=j;
                cnt++;
            }
            else if(!(g[i][j]=='.' or g[i][j]=='#')){
                st.i[g[i][j]-'A']=i;
                st.j[g[i][j]-'A']=j;
            }
        }
    }
    qq.push(st);
    visit(st);
    setDis(st,0);
    int flag=0;
    // printPos(en);
    while(!qq.empty()){
        cur = qq.front();
        // printPos(cur);
        // cout<<"--\n";
        qq.pop();
        if(over(cur,en)){
            flag=1;
            setDis(en,getDis(cur));
            while(!qq.empty())qq.pop();
            break;
        }
        for(int i=0;i<4;i++){
            pos temp = changeAll(cur,i);
            // printPos(temp);
            if(temp.i[0]==temp.i[1] and temp.j[0]==temp.j[1] and temp.i[1]==temp.i[2] and temp.j[1]==temp.j[2]){
                for(int j=0;j<3;j++){
                    temp = changeOne(cur,i,j);
                    if(!visited(temp)){
                        // printPos(temp);
                        visit(temp);
                        setDis(temp,getDis(cur)+1);
                        qq.push(temp);
                    }
                }
            }
            else if(temp.i[0]==temp.i[1] and temp.j[0]==temp.j[1]){
                pos temp2 = changeOne(cur,i,2);
                temp = changeOne(temp2,i,0);
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
                temp = changeOne(temp2,i,1);
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
            }
            else if(temp.i[0]==temp.i[2] and temp.j[0]==temp.j[2]){
                pos temp2 = changeOne(cur,i,1);
                temp = changeOne(temp2,i,0);
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
                temp = changeOne(temp2,i,2);
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
            }
            else if(temp.i[1]==temp.i[2] and temp.j[1]==temp.j[2]){
                pos temp2 = changeOne(cur,i,0);
                temp = changeOne(temp2,i,1);
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
                temp = changeOne(temp2,i,2);
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
            }
            else{
                if(!visited(temp)){
                    visit(temp);
                    setDis(temp,getDis(cur)+1);
                    qq.push(temp);
                }
            }
        }
        // cout<<"\n";
    }
    if(flag) cout<<getDis(en)<<"\n";
    else cout<<"trapped\n";
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
}
// remember these points
//  -> check if li is needed
//  -> check the constrains
//  -> check the if the value can be 0
//  -> check if the vectors, sets, maps are cleared
//  -> check if 0 is initialized to the counter or sum

int main()
{
    fast();
    // inout();
    //    t_start;
    //     for no test case
    // answer();
    precalc();

    //     when test cases exist
    test()
    {
        // cout<<"Case "<<TK<<":"<<NN;
        pcs;
        answer();
    }
        // t_show;

    return 0;
}