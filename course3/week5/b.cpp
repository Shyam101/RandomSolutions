#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int lt;
typedef vector<ll> vi;
typedef vector<int> vin;
typedef pair<ll,ll> pll;
typedef pair<int,int> pin;
typedef tuple<long double,int,int> edge;
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

const int N = 2e2+5;
int par[N];
int sz[N];

int find(int x)
{
	if(par[x]==x) return x;

	return par[x]=find(par[x]);
}

void unionn(int x,int y)
{
	int a = find(x);
	int b = find(y);

	if(x!=y)
	{
		if(sz[a]>sz[b])
			swap(a,b);

		par[a]=b;
		sz[a]+=sz[b];
	}
}

vector<pin> pnt;

long double distance(pin x,pin y)
{
	return (x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
}

void solve()
{
	int n,k;
	cin>>n;

	for(int i=0;i<n+2;++i) par[i]=i,sz[i]=1;
	pnt.resize(n);

	for(int i=0;i<n;++i) cin>>pnt[i].first>>pnt[i].second;

	cin>>k;
	priority_queue<edge,vector<edge>,greater<edge>> ed;

	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			ed.push({distance(pnt[i],pnt[j]),i,j});
		}
	}

	vector<long double> temp;
	while(!ed.empty())
	{
		long double dis = get<0>(ed.top());
		auto x = get<1>(ed.top());
		auto y = get<2>(ed.top());
		ed.pop();

		if(find(x)!=find(y))
		{
			unionn(x,y);
			temp.push_back(dis);
		}
	}

	cout<<setprecision(14)<<fixed<<sqrtl(temp[n-k])<<endl;

	//print(temp);
	//cout<<endl;

}

int main()
{
    solve();
}

