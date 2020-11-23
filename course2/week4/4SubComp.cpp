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


ll mod_pow(ll a,ll n,ll mod)	//(a^n)%mod
{	ll res=1;
	while(n){	if(n&1)	res=(res*a)%mod; n/=2; a=(a*a)%mod;	}
	return res;
}

const int p = 31;
const int m = 1e9+9;
const int N = 5e5+2;

ll ppow[N];
ll pinv[N];
vi ha;

void init()
{
	ppow[0]=1;
	for(int i=1;i<N;++i)
		ppow[i]=(ppow[i-1]*p)%m;

	ll inv = mod_pow(p,m-2,m);
	pinv[0]=1;
	for(int i=1; i<N; ++i)
		pinv[i] = (pinv[i-1]*inv)%m; 
}

vi build_Hash(string s)
{
	int n = s.size();
	vi h(n+1,0);

	for(int i=0;i<n;++i)
		h[i+1] = (h[i] + s[i]*ppow[i])%m;

	return h;
}

void solve()
{
	string s;
	cin>>s;

	ha = build_Hash(s);

	int q;
	cin>>q;
	while(q--)
	{
		int a,b,l;
		cin>>a>>b>>l;

		if(a>b) swap(a,b);

		ll hs1 = (pinv[b-a]*((ha[b+l]-ha[b]+m)%m))%m;
		ll hs2 = (ha[a+l]-ha[a]+m)%m;

		if(hs1==hs2)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;

	}
}

int main()
{
	init();
   solve();
}

