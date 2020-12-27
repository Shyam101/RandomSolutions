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
#define print(x) for(auto i:x) cout<<i<<" ";


const int mod=1e9+7;

ll mod_pow(ll a,ll n,ll mod)	//(a^n)%mod
{	ll res=1;
	while(n){	if(n&1)	res=(res*a)%mod; n/=2; a=(a*a)%mod;	}
	return res;
}

const int N = 1e5+5;
bool vis[N];
ll cost[N];
int par[N];
vin G[N];


void dfs(int u)
{
	if(vis[u]) return;
	vis[u] = 1;

	for(auto v:G[u])
	{
		dfs(v);
	}
}

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<tuple<ll,ll,ll>> a;
	rep(i,0,n+2) cost[i]=LLONG_MAX;

	rep(i,0,m)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		a.push_back({x,y,z});
		G[x].push_back(y);
	}

	ll src;
	cin>>src;

	cost[src]=0;
	vin loop;
	rep(l,0,n)
	{
		for(auto e:a)
		{
			int x = get<0>(e);
			int y = get<1>(e);
			int z = get<2>(e);

			if(cost[x]!=LLONG_MAX and cost[x]+z<cost[y])
			{
				if(l==n-1)
					loop.push_back(y);
				par[y]=x;
				cost[y] = cost[x] + z;
			}
		}
	}

	set<int> st;
	vin spc;	//all nodes which belongs to negative loop
	for(auto i:loop)
	{
		int p = i;
		while(!st.count(p))
			st.insert(p), p=par[p];
	}

	for(auto i:st)
	{
		if(!vis[i])
			dfs(i);
	}

	for(int i=1;i<=n;++i)
	{
		if(vis[i])
			cout<<'-'<<endl;
		else if(cost[i]==LLONG_MAX)
			cout<<'*'<<endl;
		else 
			cout<<cost[i]<<endl; 

	}

}

int main()
{
    solve();
}

