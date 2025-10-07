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

const i32 INF = 1e9+7;

vector<pair<i32, i32>> adj[MAXN];

bool isOk(int i, int j, vector<vector<i64>> &grid){
    return !(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size());
}

void solve(){
    i32 n,m;see(n,m);
    pair<i32, i32> grid[27][27];
    memset(grid,INF,sizeof(grid));
    rep(i,0,m){
        char a,b;i32 u;
        see(a,b,u);
        grid[a-'A'][b-'A']={u,1};
        grid[b-'A'][a-'A']={u,1};
    }
    i32 prev[27][27];
    rep(i,0,27){
        rep(j,0,27){
            prev[i][j]=i;
        }
    }
    rep(k,0,n){
        rep(i,0,n){
            rep(j,0,n){
                if(grid[i][j].ff>grid[i][k].ff+grid[k][j].ff){
                    grid[i][j].ff = grid[i][k].ff+grid[k][j].ff;
                    grid[i][j].ss = grid[i][k].ss+grid[k][j].ss;
                    prev[i][j]=prev[k][j];
                }else if(grid[i][j].ff == grid[i][k].ff+grid[k][j].ff){
                    if(grid[i][j].ss > grid[i][k].ss+grid[k][j].ss){
                        grid[i][j].ss=grid[i][k].ss+grid[k][j].ss;
                        prev[i][j]=prev[k][j];
                    }
                }
            }
        }
    }
    i32 q;see(q);
    while(q--){
        char a,b;see(a,b);
        i32 u = a-'A',v=b-'A';
        stack<int> st;
        // debug(prev[u][v]);
        while(prev[u][v]!=u){
            st.push(prev[u][v]);
            v=prev[u][v];
        }
        put((char)(u+'A'));
        while(!st.empty()){
            put((char)(st.top()+'A'));
            st.pop();
        }
        putln(b);
    }

}

i32 main(){

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     //for getting input from input.txt
    //     freopen("input1.txt","r",stdin);
    //     //for getting output from output.txt
    //     freopen("output1.txt","w",stdout);
    // #endif

    i32 t=1;
    while(t--){
        // string line;
        // getline(cin,line);
        // if(line=="0 0") break;
        // cout << "Case " << t++ << ": average length between pages = ";
        solve();
    }
    return 0;
}
