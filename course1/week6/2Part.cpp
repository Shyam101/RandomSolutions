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

map<tuple<int,int,int,int>,bool> mp;

bool dp(vin &a,int i,int s1,int s2,int s3)
{
	if(mp.count({i,s1,s2,s3}))
		return mp[{i,s1,s2,s3}];

	if(i==a.size())
		return (s1==s2 && s2==s3);

	bool res = 0;
	res |= dp(a,i+1,s1+a[i],s2,s3);
	res |= dp(a,i+1,s1,s2+a[i],s3);
	res |= dp(a,i+1,s1,s2,s3+a[i]);

	mp[{i,s1,s2,s3}] = res;

	return res;
}

void solve()
{
    int n;
	cin>>n;

	vin a(n);
	read(a);

	cout<<dp(a,0,0,0,0)<<endl;

}

int main()
{
    solve();
}

