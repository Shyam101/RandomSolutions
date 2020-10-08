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


vector<vi> mat_mul(vector<vi> a,vector<vi> b,ll m)
{
    vector<vi> c(2,vi(2));
    c[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%m;
    c[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%m;
    c[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%m;
    c[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%m;

    return c;
}


vector<vi> mod_pow(vector<vi> a, ll n,ll m)
{
    vector<vi> res{{1,0},{0,1}};
    while(n>0)
    {
        if(n&1)
            res = mat_mul(res,a,m);

        a = mat_mul(a,a,m);
        n/=2;
    }

    return res;
}

ll Fib_fast(ll n,ll m)
{
    if(n==0) return 0;

    vector<vi> a{{1,1},{1,0}};

    auto b=mod_pow(a,n-1,m);
    return b[0][0];
}

int main()
{
    ll n;
    cin>>n;

    int fn = Fib_fast(n,(ll)10);
    int fn_1 = Fib_fast(n+1,(ll)10);

    cout<<(fn*fn_1)%10<<endl;
}
