#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int lt;
typedef vector<ll> vi;
typedef vector<int> vin;
typedef pair<ll,ll> pll;
typedef pair<int,int> pin;
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<b;++i)
#define f(i,b) for(int i=0;i<b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define test(t) int t; cin>>t; while(t--) solve()
#define endl "\n"
#define p1 cout<<"YES"<<endl
#define p0 cout<<"NO"<<endl
#define fst ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read(x) for(auto &i:x) cin>>i;


int get_it(ll n,int m=10)
{
    vi a{0,1};
    if(n<2)
        return a[n]%m;
    
    int l=0;
    for(int i=2;i<=n;++i)
    {
        a[l]=(a[0]+a[1])%m;
        l^=1;
    }
    l^=1;
    return a[l];
}

int main()
{
    ll n;
    cin>>n;
    cout<<get_it(n)<<endl;
}