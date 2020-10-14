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

const int mod=1e9+7;

ll mod_pow(ll a,ll n,ll mod)	//(a^n)%mod
{	ll res=1;
	while(n){	if(n&1)	res=(res*a)%mod; n/=2; a=(a*a)%mod;	}
	return res;
}

const int N = 1e3+5;
int coins[N];

void solve()
{
    int n;
	cin>>n;

	for(int i=0; i<=n; ++i) coins[i] = INT_MAX-100;

	vector<int> dit{1,3,4};

	coins[0] = 0;
	for(int i=1;i<=n; ++i)
	{
		for(auto j:dit)
			coins[i] = min(coins[i],i-j<0?INT_MAX:coins[i-j]+1);
	}

	cout<<coins[n]<<endl;
}

int main()
{
    solve();
}

