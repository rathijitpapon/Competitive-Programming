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
#define MX 1000005
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

string str;
ll N, m, SA [MX], LCP [MX];
ll x [MX], y [MX], w [MX], c [MX];
 
inline bool cmp (const ll a, const ll b, const ll l) { return (y [a] == y [b] && y [a + l] == y [b + l]); }
 
void Sort () {
    for (ll i = 0; i < m; ++i) w [i] = 0;
    for (ll i = 0; i < N; ++i) ++w [x [y [i]]];
    for (ll i = 0; i < m - 1; ++i) w [i + 1] += w [i];
    for (ll i = N - 1; i >= 0; --i) SA [--w [x [y [i]]]] = y [i];
}
 
void DA () {
    ++N;
    for (ll i = 0; i < N; ++i) x [i] = str [i], y[i] = i;
    Sort ();
    for (ll i, j = 1, p = 1; p < N; j <<= 1, m = p) {
        for (p = 0, i = N - j; i < N; i++) y [p++] = i;
        for (ll k = 0; k < N; ++k) if (SA [k] >= j) y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i) x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (ll i = 1; i < N; ++i) SA [i - 1] = SA [i]; --N;
}
 
void kasaiLCP () {
    for (ll i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (ll i = 0, h = 0; i < N; ++i) if (c[i] > 0) {
            ll j = SA [c [i] - 1];
            while (i + h < N && j + h < N && str [i + h] == str [j + h]) ++h;
            LCP [c [i]] = h;
            if (h > 0) --h;
        }
}
 
void suffixArray () {
    m = 256;
    N = str.size();
    DA ();
    kasaiLCP ();
}


int main()
{

    fast_io;
    ll n,m,t,i,j,k,a,b,c,cs=1;
    //freopen(input.txt, r, stdin);
    //freopen(output.txt, w, stdout);

    cin>> str;
    suffixArray();

    for(i=0;i<str.size();i++)
        cout<< SA[i] << ' ';

    
    return 0;
}