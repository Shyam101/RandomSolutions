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

const int N = 1e6+5;
int ops[N];

void solve()
{
    int n;
	cin>>n;

	
	for(int i=0;i<=n; ++i) ops[i]=INT_MAX;
	ops[1]=0;



	for(int i=1;i<=n;++i)
	{
		if(i+1<=n)
			ops[i+1]=min(ops[i+1],ops[i]+1);
		if(2*i <= n)
			ops[2*i] = min(ops[2*i],ops[i]+1);

		if(3*i<=n)
			ops[3*i] = min(ops[3*i],ops[i]+1); 
	}

	vector<int> ans;
	
	while(n!=1)
	{
		ans.push_back(n);
		
		if(ops[n]==ops[n-1]+1) n = n-1;
		else if(n%2==0 && ops[n]==ops[n/2]+1) n/=2;
		else n/=3; 
	}

	ans.push_back(n);

	reverse(all(ans));

	cout<<ans.size()-1<<endl;
	for(auto i:ans) cout<<i<<" ";

	cout<<endl;

}

int main()
{
    solve();
}

