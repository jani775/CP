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

#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl

const i64 MOD = 1000000007;
const i64 MOD2 = 998244353;
const i64 MOD3 = 1000000009;
const i64 MAXN= 12;
const i64 MAXB = (1<<10)+1;
const double ERROR = 1e-6;

i32 par[MAXN],rnk[MAXN];

double dist(i32 a1, i32 b1, i32 a2, i32 b2) {
    return sqrt(pow(a1-a2,2) + pow(b1-b2,2));
}

i32 findSet(i32 i){
    if(par[i]==i) return i;
    i32 x = findSet(par[i]);
    par[i]=x;
    return x;
}

bool sameSet(i32 i,i32 j){
    i32 x = findSet(i),y=findSet(j);
    return x==y;
}

void uniteSet(i32 i,i32 j){
    if(sameSet(i,j)) return ;
    i32 x = findSet(i),y=findSet(j);
    if(rnk[x]<rnk[y]) swap(x,y);
    par[y] = x;
    if(rnk[x]==rnk[y]) rnk[x]++;
}


void solve(){
    vector<double> a,b;
    i32 n;see(n);
    rep(i,0,n){
        double u,v;see(u,v);
        a.push_back(u);
        b.push_back(v);
        par[i]=i;
        rnk[i]=1;
    }
    vector<tuple<double,i32,i32>> edges;
    rep(i,0,n){
        rep(j,i+1,n){
            edges.push_back({dist(a[i],b[i],a[j],b[j]),i,j});
        }
    }
    sort(all(edges));
    // debug(edges);
    double ans = 0.0f;
    i32 x = n;
    rep(i,0,edges.size()){
        auto [u,v,w] = edges[i];
        // debug(u,v,w);
        if(!sameSet(v,w)){
            ans+=u;
            uniteSet(v,w);
            x--;
        }
        if(x==1) break;
    }
    decput(4,ans);
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
    see(t);
    while(t--){
        solve();
    }
    return 0;
}

