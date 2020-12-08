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
vin G[N];
bool vis[N];

void solve()
{
	int n,m;
	cin>>n>>m;

	rep(i,0,m)
	{
		ll x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	int u,v;
	cin>>u>>v;

	int res = 0;
	queue<int> q;
	q.push(u);
	vis[u]=1;

	while(!q.empty())
	{
		int n = q.size();
		bool ok=0;
		res++;
		rep(i,0,n)
		{
			auto p = q.front();
			q.pop();
			for(auto i:G[p])
			{
				if(i==v){ ok=1;break;}
				if(!vis[i])
				{
					q.push(i);
					vis[i]=1;
				}
			}	
		}
		if(ok)
		{
			cout<<res<<endl;
			return;
		}
	}

	cout<<-1<<endl;

}

int main()
{
    solve();
}

