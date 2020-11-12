#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int lt;
typedef vector<ll> vi;
typedef vector<int> vin;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tll;
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

void solve()
{
	int n,m;
	cin>>n>>m;
	vi a(m),time(m),thread(m);
	read(a);

	priority_queue<pll,vector<pll>,greater<pll>> pq; //stores finish time, thread;

	for(int i=0;i<n;++i) 
		pq.push({0,i});

	for(int i=0;i<m;++i)
	{
		auto pt = pq.top();
		pq.pop();

		while(i<m && a[i]==0)
		{
			time[i]=pt.first;
			thread[i]=pt.second;
			i++;
		}
		if(i==m) break;
		time[i] = pt.first;
		thread[i] = pt.second;

		pt.first+=a[i];
		pq.push(pt);
	}

	for(int i=0;i<m;++i)
		cout<<thread[i]<<" "<<time[i]<<endl;

}

int main()
{
    solve();
}

