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

int dfs(int u,vi *a)
{
	int r=0;
	for(auto v:a[u])
		r = max(r,dfs(v,a));

	return r+1;
}

void solve()
{
    int n;
	cin>>n;

	vi a[n];

	int root;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		if(x!=-1)
			a[x].push_back(i);
		else root=i;
	}

	cout<<dfs(root,a)<<endl;
}

int main()
{
    solve();
}

