/* 
    Copyright (C) 2024 Jani Saida - All Rights Reserved
*/

#include<bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "template.cpp"
// #else
// #endif

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
#define nosol cout<<"NO SOLUTION"<<endl
#define all(x) x.begin(),x.end()
#define LSB(s) ((s) & (-s))
#define pb push_back
#define len length
#define ff first
#define ss second
#define decput(k,v) cout<<fixed<<setprecision(k)<<v<<"\n"

i32 diaSteps[2][8] = {{0,0,1,1,1,-1,-1,-1},{1,-1,-1,0,1,-1,0,1}};
i32 steps[2][4] = {{0,0,1,-1},{1,-1,0,0}};

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const i64 MOD = 1000000007;
const i64 MOD2 = 998244353;
const i64 MOD3 = 1000000009;
const i64 MAXN= 505;
const i64 MAXB = (1<<10)+1;
const double ERROR = 1e-6;

// i32 grid[MAXN][MAXN];
// bool visited[MAXN][MAXN];

// i32 dfs(i32 node,vector<bool> &visited){
//     visited[node] = true;
//     i32 ans = 1;
//     for(auto x:adj[node]){
//         if(!visited[x]) ans += dfs(x,visited);
//     }
//     return ans;
// }

bool dfs(i32 i,i32 j,i32 n,i32 m,vector<vector<i32>> &grid,i32 c,i32 target){
    grid[i][j]=c;
    bool ans = true;
    rep(k,0,4){
        i32 u = i+steps[0][k],v=j+steps[1][k];
        if((u<0)||(v<0)||(u>=n)||(v>=m)){
            ans&=false;
            continue;
        } 
        if(grid[u][v]==target) ans&=dfs(u,v,n,m,grid,c,target);
        else if(grid[u][v]!=c) {
            ans&=false;
        }
    }
    return ans;
}

string solve(i32 n,i32 m){
    vector<string> hexaGrid(n);
    rep(i,0,n) see(hexaGrid[i]);
    vector<vector<i32>> grid(n,vector<i32>(4*m,0));
    rep(i,0,n){
        rep(j,0,m){
            i32 x =0; 
            if((hexaGrid[i][j]>='0')&&(hexaGrid[i][j]<='9')) x = hexaGrid[i][j]-'0';
            else x = 10+hexaGrid[i][j]-'a';
            // i32 a1 = 
            grid[i][4*j]=(x>>3)&1;
            grid[i][4*j+1]=(x>>2)&1;
            grid[i][4*j+2]=(x>>1)&1;
            grid[i][4*j+3]=x&1;
        }
    }
    i32 count = 2;
    rep(i,0,n){
        rep(j,0,4*m){
            if(grid[i][j]==1){
                dfs(i,j,n,4*m,grid,count++,1);
            }
        }
    }
    vector<i32> holes(count,0);
    i32 t=0;
    rep(i,0,n){
        rep(j,0,4*m){
            if((grid[i][j]==0)&&(t!=0)){
                bool check2 = dfs(i,j,n,4*m,grid,t,0);
                if(check2) holes[t]++;
            }
            t=grid[i][j];
        }
        t=0;
    }
    vector<char> symbols;
    for(int i = 2; i < count; ++i)
        {
            if(holes[i] == 0)
                symbols.push_back('W');
            else if(holes[i] == 1)
                symbols.push_back('A');
            else if(holes[i] == 2)
                symbols.push_back('K');
            else if(holes[i] == 3)
                symbols.push_back('J');
            else if(holes[i] == 4)
                symbols.push_back('S');
            else if(holes[i] == 5)
                symbols.push_back('D');
        }
    sort(all(symbols));
    string ans = "";
    for(auto &x:symbols)ans+=x;
    return ans;
}

i32 main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // #ifndef ONLINE_JUDGE
	// 	//for getting input from input.txt
	// 	freopen("input1.txt","r",stdin);
	// 	//for getting output from output.txt
	// 	freopen("output1.txt","w",stdout);
	// #endif
    i32 t=1;
    // cin>>(t);
    // while((cin>>n)&&(cin>>m)){
    while(1){
        i32 n,m;see(n,m);
        if((n==0)&&(m==0)) break;
        putn("Case",t++);
        putln(":",solve(n,m));
        // solve();
    }
    // i32 m,n;
    // while(1){
    //     see(n,m);
    //     if((m==0)) break;
    //     solve(n,m);
    //     // if(t!=0) cout<<"\n";
    // }
    return 0;
}

