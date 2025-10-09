/* 
    Copyright (C) 2024 Jani Saida - All Rights Reserved
*/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;
using ld = long double;

template<typename... T>
void see(T&&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args<< " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template <typename T,typename... V>
void putn(T&& first,V&&... rest){cout<<first;((cout<<" "<<rest), ...);}
template <typename T,typename... V>
void putln(T&& first,V&&... rest){cout<<first;((cout<<" "<<rest), ...);cout<<"\n";}

template <typename T> 
T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1) x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}

template <typename T> 
T exp(T b, T p){T x = 1;while(p){if(p&1) x=(x*b);b=(b*b);p=p>>1;}return x;}

template <typename T> 
T invFermat(T a, T p){return mod_exp(a, p-2, p);}

template <typename T> 
T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}

template <typename T> 
T lcm(T a, T b){return a*(b/gcd(a,b));}


string tostring(u64 number){stringstream ss; ss<<number;return ss.str();}

i64 toint(const string &s) {stringstream ss;ss << s;i64 x;ss >> x;return x;}

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define seeset(s,n) for(i64 i=0;i<n;i++){i64 x; cin>>x; s.insert(x);}
#define rep(i,a,b) for (i64 i=a; i<b; ++i)
#define rev(i,a,b) for (i64 i=a; i>b; --i)
#define setarr(x,b) memset(x,b,sizeof(b))
#define all(x) x.begin(),x.end()
#define LSB(s) ((s) & (-s))
#define pb push_back
#define len length
#define ff first
#define ss second
#define decput(k,v) cout<<fixed<<setprecision(k)<<v<<"\n"

i32 diaSteps[2][8] = {
{0,0,1,1,1,-1,-1,-1},
{1,-1,-1,0,1,-1,0,1}};
i32 steps[2][4] = {{0,0,1,-1},{1,-1,0,0}};
i32 knightSteps[2][8] = {{1,2,-1,-2,-1,2,1,-2},{2,1,-2,-1,2,-1,-2,1}};

#define nosol cout<<"NO SOLUTION"<<endl
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl

const i64 MOD = 1000000007;
const i64 MOD2 = 998244353;
const i64 MOD3 = 1000000009;
const i64 MAXN= 1e5+5;
const i64 MAXB = (1<<10)+1;
const double ERROR = 1e-6;

const i32 INF = 1061109567 ;

vector<pair<i32, i32>> adj[MAXN];
set<i32> par[105][105];


bool isOk(int i, int j, vector<vector<i64>> &grid){
    return !(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size());
}

void edgesInPath(set<i32> &vertices,i32 a,i32 b){
    if(a==b){
        vertices.emplace(a);
        return;
    } 
    // par[a][b].size();
    vertices.emplace(b);
    for(auto &x: par[a][b]){
        // vertices.emplace(a);
        edgesInPath(vertices,a,x);
    }
}

void solve(string line){
    // cin.ignore();
    i32 n,m,bh,o,yh,mrkt;
    // debug(line);
    stringstream ss(line);
    ss>>n>>m>>bh>>o>>yh>>mrkt;
    // debug(n,m,bh,o,yh,mrkt);

    i32 grid[105][105];
    memset(grid,63,sizeof(grid));
    vector<tuple<i32,i32,i32>> edgesPresent;
    rep(i,0,m){
        getline(cin,line);
        ss.str("");
        ss.clear();
        ss<<line;
        i32 u,v,w;
        ss>>u>>v>>w;
        grid[u][v]=w;
        grid[v][u]=w;
        edgesPresent.push_back({u,v,w});
    }
    // debug(edgesPresent.size());
    rep(i,1,n+1){
        rep(j,1,n+1){
            par[i][j].clear();
            par[i][j].emplace(i);
        }
    }

    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(grid[i][j]>grid[i][k]+grid[k][j]){
                    grid[i][j]=grid[i][k]+grid[k][j];
                    par[i][j]=par[k][j];
                }else if(grid[i][j]==grid[i][k]+grid[k][j]){
                    for(auto &x:par[k][j]){
                        par[i][j].emplace(x);
                    }
                }
            }
        }
    }
    set<i32> vertices;
    i32 a=bh,b=o;
    edgesInPath(vertices,a,b);
    // debug(edges);

    memset(grid,63,sizeof(grid));

    for(auto &[x,y,w]:edgesPresent){
        // debug(x,y,w);
        grid[x][y]=w;
        grid[y][x]=w;
    }

    for(auto &x:vertices){
        rep(i,1,n+1){
            grid[x][i]=INF;
            grid[i][x]=INF;
        }
    }
    // debug(vertices);
    rep(i,1,n+1) grid[i][i]=0;
    // debug(grid);
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(grid[i][j]>grid[i][k]+grid[k][j]){
                    grid[i][j]=grid[i][k]+grid[k][j];
                    // par[i][j]=par[k][j];
                }
            }
        }
    }

    // rep(i,1,n+1) grid[i][i]=0;

    if((vertices.count(yh))||(vertices.count(mrkt))||(grid[yh][mrkt]==INF)){
        putln("MISSION IMPOSSIBLE.");
    }else putln(grid[yh][mrkt]);
}

i32 main(){

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
        //for getting input from input.txt
        freopen("input1.txt","r",stdin);
        //for getting output from output.txt
        freopen("output1.txt","w",stdout);
    #endif

    i32 t=1;
    // while(t--){
    string line;
    while(getline(cin,line)){
        // debug(line);
        solve(line);
    }
    return 0;
}
