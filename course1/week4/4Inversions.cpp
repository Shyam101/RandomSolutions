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


int merge(vi &a, int  l, int r)
{
	int res = 0,m = (l+r)>>1;

	int i = l,j = m + 1;
	vi temp(r-l+1);
	int k = 0;

	while(i<=m && j<=r)
	{
		if(a[j]>=a[i])
			temp[k++] = a[i++];
		else 
			temp[k++] = a[j++] , res+=m-i+1;
	}

	while(i<=m) temp[k++]=a[i++];
	while(j<=r) temp[k++]=a[j++];

	for(int i=l,j=0; i<=r; ++i,++j) a[i] = temp[j];

	return res;

}

int mergeShort(vi &a,int l, int r)
{
	if(l>=r) return 0;

	int mid = (l+r)>>1;

	int res=0;
	
	res += mergeShort(a,l,mid);
	res += mergeShort(a,mid+1,r);

	return res + merge(a,l,r);
}

void solve()
{
    int n;
	cin>>n;

	vi a(n);
	read(a);

	cout<<mergeShort(a,0,a.size()-1)<<endl;

}

int main()
{
    solve();
}

