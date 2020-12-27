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
vector<pair<int,int>> G[N];
ll cost[N];


void solve()
{
    int n,m;
	cin>>n>>m;

	rep(i,0,n+2) cost[i]=LLONG_MAX;

	rep(i,0,m)
	{
		int x,y,c;
		cin>>x>>y>>c;
		G[x].push_back({y,c});
	}

	int u,v;
	cin>>u>>v;

	priority_queue<pin,vector<pin>,greater<pin>> q;
	cost[u]=0;
	q.push({cost[u],u});
	
	while(!q.empty())
	{
		auto p = q.top().second;
		auto c = q.top().first;
		q.pop();
		if(cost[p]!=c)
			continue;
		for(auto u:G[p])
		{
			if(cost[u.first]>cost[p]+u.second)
			{
				cost[u.first]=cost[p]+u.second;
				q.push({cost[u.first],u.first});
			}
		}
	}
	if(cost[v]==LLONG_MAX) cost[v]=-1;
	cout<<cost[v]<<endl;

}

int main()
{
    solve();
}

