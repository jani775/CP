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


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard</title>
    <link rel="stylesheet" href="style.css">
    <style>
        body {
    font-family: Arial, sans-serif;
    margin: 0;
    padding: 0;
}

.container {
    display: flex; /* Added */
}

/* Sidebar styles */
aside {
    background-color: #555;
    color: #fff;
    width: 250px;
    min-height: 100vh; /* Updated */
    display: flex;
    flex-direction: column;
    align-items: flex-start;
    padding: 20px;
    transition: width 0.3s;
}

aside.collapsed {
    width: 80px;
}

aside button {
    background-color: transparent;
    border: none;
    color: #fff;
    cursor: pointer;
    font-size: 18px;
    outline: none;
    padding: 5px;
}

aside nav ul {
    list-style: none;
    margin: 0;
    padding: 0;
}

aside nav ul li {
    margin-bottom: 10px;
}

aside nav ul li a {
    color: #fff;
    text-decoration: none;
    transition: color 0.3s;
}

aside nav ul li a:hover {
    color: #bbb;
}

/* Main content styles */
main {
    flex: 1;
    padding: 20px;
}

h1 {
    color: #333;
    font-size: 24px;
    margin-bottom: 20px;
}

.cards {
    display: flex;
    flex-wrap: wrap;
    gap: 20px;
}

.card {
    background-color: #fff;
    border-radius: 8px;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
    padding: 20px;
    flex: 0 0 calc(50% - 10px);
}

.card h2 {
    color: #333;
    font-size: 18px;
    margin-bottom: 10px;
}

.card p {
    color: #777;
    font-size: 14px;
}

/* Footer styles */
footer {
    background-color: #333;
    color: #fff;
    padding: 20px;
    text-align: center;
}
/* Collapsed sidebar styles */
aside.collapsed nav ul li a {
    display: none;
}

aside.collapsed #sidebar-toggle::after {
    content: '\2261';
}

aside #sidebar-toggle {
    background-color: transparent;
    border: none;
    color: #fff;
    cursor: pointer;
    font-size: 24px;
    outline: none;
    padding: 5px;
}
@media (max-width: 768px) {
    aside {
        width: 80px;
    }

    aside.collapsed {
        width: 80px;
    }

    aside.collapsed #sidebar-toggle::after {
        content: '\2261';
    }
}
    </style>
</head>
<body>
    <header>
        <!-- Header content goes here -->
    </header>
    <div>
    <aside>
        <aside>
            <div>
            <button id="sidebar-toggle">Toggle Sidebar</button>
            </div>
            <nav>
                <ul>
                    <li><a href="#">Dashboard</a></li>
                    <li><a href="#">Orders</a></li>
                    <li><a href="#">Customers</a></li>
                    <li><a href="#">Products</a></li>
                    <li><a href="#">Settings</a></li>
                </ul>
            </nav>
        
        </aside>
    </aside>
    <main>
        <main>
            <h1>Admin Dashboard</h1>
                      <div class="cards">
                          <div class="flex-container">
                              <h2>Card 1</h2>
                              <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
                          </div>
                          <div class="flex-container">
                              <h2>Card 2</h2>
                              <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
                          </div>
                          <div class="flex-container">
                              <h2>Card 3</h2>
                              <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
                          </div>
                          <div class="flex-container">
                              <h2>Card 4</h2>
                              <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit.</p>
                          </div>
                      </div>
          </main>
    </main>
    </div>
    <footer>
        <!-- Footer content goes here -->
    </footer>
    <script src="script.js"></script>
    <script>
        function toggleSidebar() {
    const sidebar = document.querySelector('aside');
    sidebar.classList.toggle('collapsed');
}
    </script>
    
</body>
</html>