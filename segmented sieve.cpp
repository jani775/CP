#include<bits/stdc++.h>
#include <sstream>
using namespace std;
 
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
 
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
 
string tostring(ll number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}

typedef long long int lli;
using u64 = uint64_t;

const long INF = LONG_MAX;
const int MOD = 1e9+7;
const int MAXN= 2e5+1;

void solve(){
    int a,b;see(a,b);
    vector<int> primes_upto_sqrtb;
    int nsqrt = sqrt(b);
    vector<bool> primes_check(nsqrt+1,true);
    for(int i=2;i*i<=b;i++){
        if(primes_check[i]){
            primes_upto_sqrtb.push_back(i);
            for(int j=i*i;j<=nsqrt;j+=i){
                primes_check[i]=false;
            }
        }
    }

    vector<bool> primes_in_range(b-a+1,true);
    for(auto p:primes_upto_sqrtb){
        int start_idx = max(p*p,((a+p-1)/p)*p);
        for(;start_idx<=b;start_idx+=p){
            primes_in_range[start_idx-a]=false;
        }
    }
    if(a==1) primes_in_range[0]=false;
    rep(i,0,b-a+1){
        if(primes_in_range[i]) putl(a+i);
    }
    cout<<"\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    see(t);
    while(t--){
        solve();
    }
    return 0;
}
 