#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int lt;
typedef long double ld;
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

float dist(pll a,pll b)
{
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

float HandleStrip(vector<pll> p,float d)
{
	sort(all(p),[&](pll &a, pll &b){
		return a.second<b.second;
	});

	for(int i=0; i<p.size(); ++i)
		for(int j=i+1; j<p.size() && p[j].second-p[i].second<=d; ++j)
			d = min(d,dist(p[i],p[j]));

	return d;
}

float MinDist(vector<pll> &a, int l, int r)
{

	if(r-l+1<=3)
	{
		float d = FLT_MAX;
		for(int i=l; i<=r; ++i)
			for(int j=i+1; j<=r; ++j)
				d = min(d,dist(a[i],a[j]));

		return d;
	}

	int m = (l+r)/2;

	float d1 = MinDist(a,l,m);
	float d2 = MinDist(a,m+1,r);

	auto d = min(d1,d2);

	vector<pll> strip;
	for(int i=l; i<=r; ++i)
		if(abs(a[i].first-a[m].first)<=d)
			strip.push_back(a[i]);

	d = min(d,HandleStrip(strip,d));

	return d;

}

void solve()
{
	int n;
	cin>>n;

	cout<<fixed<<setprecision(7);

	vector<pll> a(n);
	for(auto &i:a)
		cin>>i.first>>i.second;

	sort(all(a));

	cout<<MinDist(a,0,n-1)<<endl; 
}

int main()
{
	solve();
}