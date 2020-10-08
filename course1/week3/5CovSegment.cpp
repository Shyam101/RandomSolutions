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

void min_lines()
{
    int n;
	cin>>n;

	vector<pin> a(n);

	for(auto &i:a) cin>>i.first>>i.second;

	sort(all(a),[&](pin &x, pin &y)
	{
		return x.second<y.second;
	});

	int cur=-1;
	vector<int> pos;

	for(auto i:a)
	{
		if(i.first>cur)
		{
			cur=i.second;
			pos.push_back(cur);
		}
	}

	cout<<pos.size()<<endl;
	for(auto i:pos) cout<<i<<" ";

	cout<<endl;

}

int main()
{
    min_lines();
}

