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
vector<pair<ll,ll>> G[N];
ll cost[N];
bool vis[N];


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

	rep(src,1,n+1)
	{
		if(!vis[src])
		{
			cost[src]=0;
			vis[src]=1;
			rep(l,0,n)
			{
				for(int i=1;i<=n;++i)
				{
					for(auto u:G[i])
					{
						if(cost[i]!=LLONG_MAX and cost[u.first]>cost[i]+u.second) //u dest i src
						{
							if(l==n-1)
							{
								cout<<1<<endl;
								return;
							}
							cost[u.first]=cost[i]+u.second;
							vis[u.first]=1;
						}
					}
				}
			}
		}
	}

	cout<<0<<endl;
	
}

int main()
{
    solve();
}


