#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<ll> a(n);
    for(auto &i:a) cin>>i; 

    int ind = max_element(a.begin(),a.end())-a.begin();
    ll f = a[ind];
    a[ind]=-1;
    ll s = *max_element(a.begin(),a.end());

    cout<<f*s<<endl;
}