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

const ll mod = 1e9+9;
const ll x = rand()%(mod-2) + 2;
vi hs;
int n,m;


ll polyhash(string s)
{
	ll res = 0;
	for(int i=s.size()-1; i>=0; --i)
		res = (res*x + s[i])%mod;

	return res;
}

void precomute(string s)
{
	hs.resize(n-m+1);	

	string temp = s.substr(n-m);

	hs[n-m] = polyhash(temp);
	
	ll y = 1;
	for(int i=0;i<m;++i)
		y = (y*x)%mod;

	for(int i=n-m-1; i>=0; --i)
		hs[i] = (x*hs[i+1] + s[i] - y*s[i+m])%mod;
}

vin rabinkarp(string s,string p)
{
	vin res;
	ll  ph = polyhash(p);
	precomute(s);
    
	for(int i=0;i<=n-m; ++i)
	{
		if(ph==hs[i])
		{
			string temp = s.substr(i,m);
			if(temp==p)
				res.push_back(i);
		}
	}
	return res;
}


void solve()
{
    string txt,pat;
	cin>>pat>>txt;

	n=txt.size(),m=pat.size();
	
	auto v = rabinkarp(txt,pat);

	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
   solve();
}

