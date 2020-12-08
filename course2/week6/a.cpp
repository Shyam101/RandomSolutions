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

const int mod = 1e9 + 7;

ll mod_pow(ll a, ll n, ll mod) //(a^n)%mod
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * a) % mod;
		n /= 2;
		a = (a * a) % mod;
	}
	return res;
}

struct node
{
	ll val;
	node *left, *right;

	node(ll data)
	{
		val = data;
	}
};

void inorder(node *r)
{
	if(r==NULL) return;

	inorder(r->left);
	cout<<r->val<<" ";
	inorder(r->right);
}

void preorder(node *r)
{
	if(r==NULL) return;

	cout<<r->val<<" ";
	preorder(r->left);
	preorder(r->right);
}

void postorder(node *r)
{
	if(r==NULL) return;

	postorder(r->left);
	postorder(r->right);
	cout<<r->val<<" ";
}

void solve()
{
	int n;
	cin>>n;
	vector<node*> temp(n);
	vector<int> childy(n),childz(n);
	
	for(int i=0;i<n;++i)
	{
		ll x;
		int y,z;
		cin>>x>>y>>z;
		temp[i] = new node(x);
		childy[i] = y;
		childz[i] = z;
	}

	for(int i=0;i<n;++i)
	{
		if(childy[i]!=-1)
			temp[i]->left = temp[childy[i]];
		if(childz[i]!=-1)
			temp[i]->right = temp[childz[i]];
	}

	inorder(temp[0]);
	cout<<endl;
	preorder(temp[0]);
	cout<<endl;
	postorder(temp[0]);
	cout<<endl;
}

int main()
{
	solve();
}
