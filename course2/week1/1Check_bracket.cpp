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

bool is_bracket(char c)
{
	return c=='(' or c ==')' or c=='{' or c=='}' or c=='[' or c==']';
}

bool is_matching(char c,char d)
{
	return (c=='{' and d=='}') or (c=='[' and d==']') or (c=='(' and d==')');
}

bool is_opning(char c)
{
	return c=='(' or c=='{' or c=='[';
}

void solve()
{
    string s;
	cin>>s;

	stack<char> ct;
	stack<int> ind;

	for(int i=0;i<s.size();++i)
	{
		if(is_bracket(s[i]))
		{
			if(is_opning(s[i]))
			{
				ct.push(s[i]);
				ind.push(i);
				continue;
			}

			if(ct.empty() or !is_matching(ct.top(),s[i]))
			{
				cout<<i+1<<endl;
				return;
			}

			ct.pop();
			ind.pop();
		}
	}

	while(ind.size()>1) ind.pop();

	if(ind.empty())
		cout<<"Success"<<endl;
	else 
		cout<<ind.top()+1<<endl;

}

int main()
{
    solve();
}

