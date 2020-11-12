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

const int N = 1e5+6;
int par[N];
int sz[N];

int find(int n)
{
	if(par[n]==n) return n;

	return par[n]=find(par[n]);
}

int unionn(int a,int b)
{
	int x = find(a);
	int y = find(b);

	if(x!=y)
	{
		if(sz[x]<sz[y])
			swap(x,y);
		par[y]=x;
		sz[x]+=sz[y];
	}

	return x;
}

void solve()
{
    int n,q;
	cin>>n>>q;

	for(int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		par[i]=i;
		sz[i]=x;
	}

	int mx = *max_element(sz,sz+n+4);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		mx = max(mx,sz[unionn(x,y)]);
		cout<<mx<<endl;
	}
}

int main()
{
	fst;
    solve();
}

