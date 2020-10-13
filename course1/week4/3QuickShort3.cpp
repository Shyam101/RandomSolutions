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


pin partition3(vector<int> &a, int l, int r) {

  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);

  int k = j-1;
  for(int i = l; i<k; ++i)
  {
	  while(a[i]==a[j] && i<k)
	  {
			swap(a[i],a[k]);
			k--;
	  }
  }
  return {k,j+1};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  auto m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first);
  randomized_quick_sort(a, m.second, r);
}

void solve()
{
	int n;
	cin>>n;
	vin a(n);
	read(a);
	randomized_quick_sort(a,0,a.size()-1);


	for(auto i:a)
		cout<<i<<" ";

	cout<<endl;
}

int main()
{
    solve();
}

