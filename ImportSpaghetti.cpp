/* 
    Copyright (C) 2024 Jani Saida - All Rights Reserved
*/

#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "template.cpp"
// #else
// #define debug(...)
// #define debugArr(arr, n)
// #endif

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
const i32 INF2 = 1e9+7 ;

vector<pair<i32, i32>> adj[MAXN];
set<i32> par[105][105];


bool isOk(int i, int j, vector<vector<i64>> &grid){
    return !(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size());
}

void solve(){
    i32 n;see(n);
    // debug(n);
    map<string, i32> mp;
    map<i32, string> tmp;
    rep(i,0,n){
        string s;see(s);
        mp.emplace(s,i);
        tmp.emplace(i,s);
    }
    // debug(mp,tmp);
    i32 grid[505][505];
    memset(grid,63,sizeof(grid));
    string line;
    getline(cin,line);
    rep(i,0,n){
        getline(cin,line);
        // debug(line);
        stringstream ss(line);
        string a;i32 b;
        ss>>a>>b;
        // debug(a,b);
        i32 sec = mp[a];
        rep(i,0,b){
            ss.str("");
            ss.clear();
            getline(cin,line);
            ss<<line;
            string x;ss>>x;
            // debug(x);
            vector<string> impts;
            while(ss>>x){
                if(x[x.size()-1]==','){
                    x = x.substr(0,x.size()-1);
                }
                grid[sec][mp[x]]=1;
            }
        }
    }

    i32 par[505][505];
    rep(i,0,505){
        rep(j,0,505){
            par[i][j]=i;
        }
    }

    rep(k,0,n){
        rep(i,0,n){
            rep(j,0,n){
                if (grid[i][k] + grid[k][j] < grid[i][j]) {
                    grid[i][j] = grid[i][k] + grid[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }

    i32 minWt = INF,minWtIdx = -1;
    rep(i,0,n){
        if(minWt>grid[i][i]){
            minWt=grid[i][i];
            minWtIdx=i;
        }
    }
    if(minWtIdx==-1){
        putln("SHIP IT");
    }else{
        vector<i32> cycle;
        cycle.push_back(minWtIdx);
        i32 cur = par[minWtIdx][minWtIdx];
        while(cur!=minWtIdx){
            cycle.push_back(cur);
            cur = par[minWtIdx][cur];
        }
        reverse(all(cycle));
        for(auto &x:cycle){
            put(tmp[x]);
        }
        cout<<"\n";
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

    i32 t=1,test=1;
    // see(t);
    while(t--){
    // while(t){
        // i32 n,m,q;see(n,m,q);
        // if((n==0)&&(m==0)&&(q==0)) break;
        // while(test<=t){
        // put("Case",tostring(test)+":");
        solve();
    }
    return 0;
}
