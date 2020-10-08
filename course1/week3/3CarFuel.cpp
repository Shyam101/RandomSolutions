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

void minRefill()
{
    int d,m,n;
	cin>>d>>m>>n;

	vin a(n+1);
	a[0]=0;
	for(int i=1;i<n+1;++i) cin>>a[i];
	a.push_back(d);

	int res=0,cur=m;

	for(int i=1; i<n+2; ++i)
	{
		if(cur<a[i])
		{
			cur = a[i-1]+m;
			res++;

			if(cur<a[i])
			{
				cout<<-1<<endl;
				return;
			}
		}
	}

	cout<<res<<endl;

}

int main()
{
    minRefill();
}

