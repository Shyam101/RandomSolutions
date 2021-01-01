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

struct node{
	node* a[4]; //A C G T
};

map<int,char> mp{{0,'A'},{1,'C'},{2,'G'},{3,'T'}};

map<char,int> mp1{{'A',0},{'C',1},{'G',2},{'T',3}};


class Trie{
	node* root;// = new node();

	public:

	Trie()
	{
		root = new node();
	}

	void insert(string s)
	{
		node *r= root;
		int i=0;
		while(i<s.size())
		{
			if(!r->a[mp1[s[i]]])
				r->a[mp1[s[i]]] = new node();
			
			r = r->a[mp1[s[i]]];
			i++;
		}
	}

	void printd(node* r,int & ind)
	{
		int temp = ind;
		for(int i=0;i<4;++i)
		{
			if(r->a[i])
			{
				cout<<temp<<"->"<<(ind+1)<<":"<<mp[i]<<endl;
				ind++;
				printd(r->a[i],ind);
			}
		}
	}
	void printTrie()
	{
		int ind = 0;
		printd(root,ind);
	}

};

void solve()
{
	int n;
	cin>>n;

	Trie* t = new Trie();

	while(n--)
	{
		string s;
		cin>>s;
		t->insert(s);
	}

	t->printTrie();
}

int main()
{
    solve();
}
