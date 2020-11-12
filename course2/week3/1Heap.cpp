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

vector<pin> swaps;

void heapify(int i,vin &a)
{
	int n = a.size();
	int mn = a[i];
	if(i*2+1<n) 
		mn = min(mn,a[i*2+1]);
	if(i*2+2<n)
		mn = min(mn,a[2*i+2]);

	if(mn==a[i]) return;
	if(mn ==a[i*2+1]) 
	{
		swap(a[i],a[2*i+1]);
		swaps.push_back({i,2*i+1});
		heapify(2*i+1,a);
	}
	else 
	{
		swap(a[i],a[i*2+2]);
		swaps.push_back({i,2*i+2});
		heapify(2*i+2,a);
	}
}	

void solve()
{
    int n;
	cin>>n;

	vin a(n);
	read(a);

	for(int i=n/2;i>=0;--i)
		heapify(i,a);

	cout<<swaps.size()<<endl;
	for(auto i:swaps)
		cout<<i.first<<" "<<i.second<<endl;

}

int main()
{
    solve();
}

