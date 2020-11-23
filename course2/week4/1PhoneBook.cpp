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

//hashing using direct address;

class mmap{
	const static int N=1e5;
	vector<pair<int,string>> a[N];// = new int[N];
	int aa,b;

	private:
	int hashkey(int num)
	{
		return (1ll*aa*num + b)%N;
	}

	public:
	mmap()
	{
		aa = rand()%N;
		b = rand()%N;
	}

	void add(int num,string name)
	{
		int ind = hashkey(num);
		for(int i=0;i<a[ind].size();++i)
		{
			if(a[ind][i].first==num)
			{
				a[ind][i].second=name;
				return;
			}
		}
		a[ind].push_back({num,name});
	}

	string find(int num)
	{
		for(auto i:a[hashkey(num)])
		{
			if(i.first==num) return i.second;
		}
		return "not found";
	}

	void del(int num)
	{
		int ind = hashkey(num);
		for(int i=0;i<a[ind].size();++i)
		{
			if(a[ind][i].first==num)
			{
				swap(a[ind][i],a[ind].back());
				a[ind].pop_back();
				return;
			}
		}
	}
};


void solve()
{
    int n;
	cin>>n;

	mmap mp;

	string s;
	int num;
	while(n--)
	{
		cin>>s>>num;
		if(s=="add")
		{
			string name;
			cin>>name;
			mp.add(num,name);
		}
		else if(s=="find")
			cout<<mp.find(num)<<endl;
		else 
			mp.del(num);
	}
	
}

int main()
{
   solve();
}

