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

const int mod=1e9+7;
const int x = 31;
const int N = 2e5+2;

int n,m;
vi ha,hb;
ll ppow[N],pinv[N];

void init()
{
	ppow[0]=1;
	for(int i=1;i<N;++i)
		ppow[i]=(ppow[i-1]*x)%mod;

	ll inv = mod_pow(x,mod-2,mod);
	pinv[0]=1;
	for(int i=1; i<N; ++i)
		pinv[i] = (pinv[i-1]*inv)%mod; 
}

vi buildhash(string s)
{
	int n = s.size();
	vi h(n+1,0);
	for(int i=0;i<n;++i)
		h[i+1] = (h[i] + s[i]*ppow[i])%mod;
	
	return h;
}

int get_next(string &s,string &p,int l,int r,int offset) //get next mismatch
{
	ll res=-1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		//calculate hash of p till mid and for s till offset+l to offset+mid
		ll cur_ph = (ha[offset+mid+1]-ha[offset+l]+mod)%mod;
		cur_ph = (cur_ph*pinv[offset+l])%mod;
		ll cur_sh = (hb[mid+1] - hb[l]+mod)%mod;
		cur_sh = (cur_sh*pinv[l])%mod;

		if(cur_ph==cur_sh)
			l=mid+1;
		else 
		{
			res = mid;
			r=mid-1;
		}
	}
	return res;
}

bool check(string &s,string &p,int i,int k) //k mismatch offset = i
{
	int l=0,r=m-1;
	int temp;
	k++;
	while((temp=get_next(s,p,l,r,i))!=-1 && k)
	{
		k--;
		l=temp+1;
	}
	return k;

}

vin rabin_karp(string &s,string &p,int k)
{
	vin res;
	ha = buildhash(s);
	hb = buildhash(p);

	for(int i=0;i<=n-m;++i)
	{
		if(check(s,p,i,k))
			res.push_back(i);
	}

	return res;
}


void solve(string s,string p,int k)
{
    n = s.size();
	m = p.size();

	auto v = rabin_karp(s,p,k);

	cout<<v.size()<<" ";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
	init();
	string s,p;
	int k;
	while(cin>>k>>s>>p)
   		solve(s,p,k);
}

