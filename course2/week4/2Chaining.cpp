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

class mmap{
	static const int p = 1e9+7,x=263;
	vector<list<string>> a;
	int m;

	private:
	int hashkey(string s)
	{
		ll res=0;
		for(ll i=0;i<s.size();++i)
		{
			res += int(s[i])*(mod_pow(x,i,p));
			res %= p;
		}
			
		return res%m;
	}

	public:
	mmap(int n)
	{
		m = n;
		a.resize(m);
	}

	void add(string s)
	{
		int h = hashkey(s);
		auto it = std::find(a[h].begin(),a[h].end(),s);

		if(it==a[h].end())
			a[h].push_front(s);
	}
	
	bool find(string s)
	{
		int h = hashkey(s);
		auto it = std::find(a[h].begin(),a[h].end(),s);
		
		return it!=a[h].end();
	}

	void del(string s)
	{
		int h = hashkey(s);
		auto it = std::find(a[h].begin(),a[h].end(),s);

		if(it!=a[h].end())
			a[h].erase(it);
	}

	void check(int i)
	{
		for(auto i:a[i]) cout<<i<<" ";
		cout<<endl;
	}
};

void solve()
{
	int m,n;
	cin>>m>>n;

	mmap mp(m);

	string s;
	string arg;
	while(n--)
	{
		cin>>s>>arg;
		if(s=="add")
			mp.add(arg);
		else if(s=="find")
		{
			if(mp.find(arg)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
		else if(s=="del")
			mp.del(arg);
		else 
		{
			mp.check(stoi(arg));
		}
	}

    
}

int main()
{
	fst;
   solve();
}

