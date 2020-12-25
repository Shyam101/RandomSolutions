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

const int N = 1e5+5;
vin G[N];
vin R[N];
bool vis[N];
stack<int> st;

void dfs(int u)
{
	if(vis[u]) return;
    vis[u]=1;
    for(auto i:G[u])
        dfs(i);

        st.push(u);
}

void dfs2(int u)
{
	if(vis[u]) return;
    vis[u]=1;
    for(auto i:R[u])
        dfs2(i);

}

void solve()
{
	int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        R[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
	{
		if(!vis[i])
			dfs(i);
	}

    memset(vis,0,sizeof vis);
    int cnt=0;
    while(st.size())
    {
        auto p = st.top();
        st.pop();
        if(!vis[p])
            dfs2(p),cnt++;
    }

    cout<<cnt<<endl;

}

int main()
{
    solve();
}