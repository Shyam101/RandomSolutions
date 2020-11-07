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

ll eval(ll x,ll y,char c)
{
		if(c=='*') return x*y;
		else if(c=='+') return x+y;
		else if(c=='-') return x-y;
		else 
		{
			assert(0);
			return 0;
		}
}


ll dp(const string &s)
{
	int n = s.size();
	int nums = (n+1)/2;
	
	ll mn[nums][nums];
	ll mx[nums][nums];

	memset(mn,0,sizeof mn);
	memset(mx,0,sizeof mx);

	for(int i=0;i<nums;++i)
		mn[i][i]=mx[i][i] = (ll)(s[2*i]-'0');

	for(int z = 0; z<nums-1;z++)
	{
		for(int i =0;i<nums-z-1;i++)
		{
			int j=i+z+1;
			ll mnval=LLONG_MAX,mxval=LLONG_MIN;
			
			for(int k=i;k<j;k++)
			{
				ll a = eval(mn[i][k],mn[k+1][j],s[2*k+1]);
				ll b = eval(mn[i][k],mx[k+1][j],s[2*k+1]);
				ll c = eval(mx[i][k],mn[k+1][j],s[2*k+1]);
				ll d = eval(mx[i][k],mx[k+1][j],s[2*k+1]);
				mnval = min(mnval,min(a,min(b,min(c,d))));
				mxval = max(mxval,max(a,max(b,max(c,d))));
			}
			mx[i][j] = mxval;
			mn[i][j] = mnval;
		}
	}
	return mx[0][nums-1];
}

void solve()
{
	string s;
	cin>>s;

	cout<<dp(s)<<endl;

}

int main()
{
    solve();
}

