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


const int mod=1e9+7;

ll mod_pow(ll a,ll n,ll mod)	//(a^n)%mod
{	ll res=1;
	while(n){	if(n&1)	res=(res*a)%mod; n/=2; a=(a*a)%mod;	}
	return res;
}

const int p = 31;
const int m = 1e9+9;
const int N = 1e5;

ll ppow[N];
ll pinv[N];
vi ha,hb;
int x,y;

void init()
{
	ppow[0]=1;
	for(int i=1;i<N;++i)
		ppow[i]=(ppow[i-1]*p)%m;

	ll inv = mod_pow(p,m-2,m);
	pinv[0]=1;
	for(int i=1; i<N; ++i)
		pinv[i] = (pinv[i-1]*inv)%m; 
}

vi build_Hash(string s)
{
	int n = s.size();
	vi h(n+1,0);

	for(int i=0;i<n;++i)
		h[i+1] = (h[i] + s[i]*ppow[i])%m;

	return h;
}


pin check(int k,string a,string b)
{
	unordered_map<ll,vin> mp;

	for(int i=0; i<=x-k; ++i)
	{
		ll cur_h = (ha[i+k]-ha[i] + m)%m;
		cur_h = (cur_h * pinv[i])%m;
		mp[cur_h].push_back(i);
	}

	for(int i=0;i<=y-k; ++i)
	{
		ll cur_h = (hb[i+k]-hb[i]+m)%m;
		cur_h = (cur_h*pinv[i])%m;

		if(mp.count(cur_h))
		{
			for(auto l:mp[cur_h])
			{
				string temp1 = a.substr(l,k);
				string temp2 = b.substr(i,k);
				if(temp1 == temp2)
					return {l,i};
			}
		}
	}
	return {-1,-1};
}

void solve(string s,string t)
{
	x = s.size();
	y = t.size();

	ha = build_Hash(s);
	hb = build_Hash(t);

	int l=0,r=min(x,y);

	int res=0;
	pin pt;
	while(l<=r)
	{
		int mid = (l+r)>>1;
		auto temp = check(mid,s,t);
		if(temp != make_pair(-1,-1))
		{
			pt = temp;
			res = mid;
			l = mid+1;
		}
		else 
			r = mid-1;
	}

	cout<<pt.first<<" "<<pt.second<<" "<<res<<endl;

}

int main()
{
	init();
	string s,t;
	while(cin>>s>>t)
		solve(s,t);

}

