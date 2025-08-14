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
const i64 MAXN= 3e4+2;
const i64 MAXB = (1<<10)+1;
const double ERROR = 1e-6;

vector<tuple<i32,i32,i32>> edges;
vector<i32> adj[MAXN];
i32 par[MAXN],rnk[MAXN];

bool comparator(tuple<i32,i32,i32> &a,tuple<i32,i32,i32> &b){
    return (get<2>(a))<(get<2>(b));
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

void solve(i32 n,i32 m){
    edges.clear();
    // rep(i,0,MAXN) adj[i].clear();
    rep(i,0,n){
        par[i]=i;
        rnk[i]=1;
    }
    rep(i,0,m){
        i32 u,v,w;see(u,v,w);
        edges.push_back(make_tuple(u,v,w));
    }
    // debug(edges);
    sort(all(edges),comparator);
    i32 totalSets = n,i=0;
    vector<bool> check(m,false);
    for(auto &[u,v,w]:edges){
        // debug(u,v);
        if(!sameSet(u,v)){
            // debug(u,v);
            totalSets--;
            uniteSet(u,v);
            check[i]=true;
        }
        i++;
    }
    // debug(check,totalSets);
    vector<i32> a;
        rep(i,0,m){
            if(!check[i]) {
                a.push_back(get<2>(edges[i]));
            }
        }
        if(a.size()==0){
            putln("forest");
            return;
        }
        sort(all(a));
        bool ch = false;
        for(auto x:a) {
            if(ch) put("");
            else ch=true;
            putn(x);
        }
        cout<<"\n";
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
    // see(t);
    while(1){
        i32 n,m;see(n,m);
        if((n==0)&&(m==0)) break;
        solve(n,m);
        if(t==17){
            
        }
    }
    return 0;
}
