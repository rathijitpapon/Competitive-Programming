#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define fast_io ios_base::sync_with_stdio(0); //cin.tie(0);
#define ll long long
#define ld long double
#define pb push_back
#define loop(i,n) for(i=1;i<=n;i++)
#define loon(i,n) for(i=n;i>0;i--)
#define pii pair< int,int > 
#define pll pair< ll,ll > 
#define vii vector< int > 
#define vll vector< ll > 
#define vss vector< string > 
#define vdd vector< double > 
#define vpi vector< pii > 
#define vpl vector< pll > 
#define vvi vector< vii > 
#define vvl vector< vll > 
#define PQ priority_queue
#define MX 10000005
#define mod 1000000007
#define INF 10000000000000
#define EPS 1e-12

/* Special functions:
        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
pii(ll,ll),					// type long long
null_type,
less<pii(ll,ll)>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct compare{
    bool operator() (ll a, ll b)
    {
        return a>b;
    }
};

vll pref_func(string str)
{
    ll n=str.size();
    vll v(n);
    v[0]=0;
    for(ll i=1;i<n;i++){
        ll j=v[i-1];
        while(j>0 and str[i]!=str[j])
            j=v[j-1];
        if(str[i]==str[j])
            j++;
        v[i]=j;
    }

    return v;
}


int main()
{

    fast_io;
    ll n,m,t,i,j,k,a,b,c,cs=1;
    //freopen(input.txt, r, stdin);
    //freopen(output.txt, w, stdout);
    string str;

    cin>> str;
    vll v=pref_func(str);

    for(i=0;i<str.size();i++)
        cout<< v[i] << ' ';
    cout<< endl;
    return 0;
}