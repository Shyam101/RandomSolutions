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

const int N = 103;
int dp[N][N][N];

int n,m,l;
vin a,b,c;


void solve()
{
    cin>>n;
	a.resize(n); read(a);

	cin>>m;
	b.resize(m); read(b);

	cin>>l;
	c.resize(l); read(c);

	for(int i=0; i<=n; ++i)
		for(int j=0; j<=m; ++j)
			for(int k=0; k<=l; ++k)
			{
			
				if(i==0 || j==0 || k==0) 
					dp[i][j][k] = 0;
				else if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				else 
					dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));

			}


	cout<<dp[n][m][l]<<endl;
}

int main()
{
    solve();
}

