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

class stk{
	stack<int> st;
	stack<int> m;

	public:
		void push(int x)
		{
			st.push(x);
			if(m.empty() || m.top()<=x) m.push(x); 
		}

		void pop()
		{
			if(m.top()==st.top()) m.pop();
			st.pop();
		}

		int max()
		{
			return m.top();
		}
};


void solve()
{
    int n;
	cin>>n;

	stk st;
	for(int i=0;i<n;++i)
	{
		string s;
		cin>>s;

		if(s=="push") 
		{
			int x;
			cin>>x;
			st.push(x);
		}
		else if(s=="pop")	st.pop();
		else cout<<st.max()<<endl;
	}
}

int main()
{
	fst;
    solve();
}

