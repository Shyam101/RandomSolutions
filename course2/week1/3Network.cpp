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

void solve()
{
    int s,n;
	cin>>s>>n;

	queue<int> q;
	vi res(n);

	for(int i=0;i<n;++i)
	{
		int x,y;
		cin>>x>>y;

		while(!q.empty() && q.front()<=x)
			q.pop();

		if(q.size()==s) res[i]=-1;
		else 
		{
			res[i]=q.empty()?max(0,x):q.back();
			q.push(res[i]+y);
		}
	}

	for(auto i:res) cout<<i<<" ";
	cout<<endl;
}

int main()
{
    solve();
}

