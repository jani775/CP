#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif

template<typename... T>
void see(T&&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args<< " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define inputv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define outputv(v,n) for(int i=0;i<n;i++){cout<<v[i]<<" ";}cout<<"\n";
#define seeset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define decput(a,b) cout<<fixed<<setprecision(a)<<b<<endl;
#define seevec(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define setarr(x,b) memset(x,b,sizeof(b))
#define nosol cout<<"NO SOLUTION"<<endl
#define all(x) x.begin(),x.end()
#define ll long long int 
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define LSB(s) ((s) & (-s))
#define pb push_back
#define rsz resize
#define len length
#define sz size

using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;

template <typename T> 
 T mod_exp(T b, T p, T m){
    T x = 1;
   while(p){
       if(p&1) x=(x*b)%m;
       b=(b*b)%m;
       p=p>>1;
    }
    return x;
}

template <typename T> 
T exp(T b, T p){
    T x = 1;
    while(p){
        if(p&1) x=(x*b);
        b=(b*b);
       p=p>>1;
    }
    return x;
}

template <typename T> 
T invFermat(T a, T p){
    return mod_exp(a, p-2, p);
}

template <typename T> 
T gcd(T a, T b){
    return (b==0)?a:gcd(b,a%b);
}

template <typename T> 
T lcm(T a, T b){
    return a*(b/gcd(a,b));
}

string tostring(u64 number){
    stringstream ss; 
    ss<<number; 
    return ss.str();
}

i64 toint(const string &s) {
    stringstream ss; 
    ss << s; 
    i64 x; 
  
    return x;
}
const i64 MOD = 1000000007;
const i64 MOD2 = 998244353;
const i64 MOD3 = 1000000009;
const i64 MAXN= 1e6;


int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}


int main(){
    // #ifndef ONLINE_JUDGE
    //     //for getting input from input.txt
    //     freopen("input1.txt","r",stdin);
    //     //for getting output from output.txt
    //     freopen("output1.txt","w",stdout);
    // #endif
	srand(time(NULL));
    i32 t = rand(2,10);
    putl(t);
    while(t--){
        i32 n = rand(2,10);
        putl(n);
        
        //random tree
        // vector<pair<i32, i32>> edges;
        // rep(i,2,n+1){
        //     edges.emplace_back(rand(1,i-1),i);
        // }

        // vector<i32> perm(n+1);
        // rep(i,1,n+1){
        //     perm[i]=i;
        // }

        // shuffle(perm.begin()+1,perm.end(),default_random_engine(0));
        // shuffle(edges.begin(),edges.end(),default_random_engine(0));

        // for(auto [a,b]:edges){
        //     if(rand()%2) swap(a,b);
        //     putl(perm[a],perm[b],rand()%10+1);
        // }

        rep(i,2,n+1){
            putl(rand(1,1),i,rand()%10+1);
        }
    }
	return 0;
}

