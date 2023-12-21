/*
    written by Pankaj Kumar.
    country:-INDIA
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define speed    \
    cin.tie(0);  \
    cout.tie(0); \
    ios_base::sync_with_stdio(0);
/*  Abbrevations  */
#define ff first
#define ss second
#define mp make_pair
#define line cout << endl;
#define pb push_back
// Some print
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
// sort
#define all(V) (V).begin(), (V).end()
#define srt(V) sort(all(V))
#define srtGreat(V) sort(all(V), greater<ll>())
// some extra
#define printv(v)                         \
    for (ll i = 0; i < ll(v.size()); i++) \
    {                                     \
        cout << v[i] << " ";              \
    }                                     \
    line;
#define precision(x) cout << fixed << setprecision(x);
#define sz(V) ll(V.size())
// datatype definination
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

class Codeforces
{
private:
    // read only variable
    const ll INF = 1e18;
    const ll mod1 = 1e9 + 7;
    const ll mod2 = 998244353;

public:
    Codeforces()
    {
    }

    ll power(ll x, ll y)
    {
        ll result = 1;
        while (y > 0)
        {
            if (y & 1)
            {
                result *= x;
            }
            y >>= 1;
            x *= x;
        }
        return result;
    }

    ll power(ll x, ll y, ll mod)
    {
        ll result = 1;
        x %= mod;
        while (y > 0)
        {
            if (y & 1)
            {
                result *= x;
                result %= mod;
            }
            y >>= 1;
            x *= x;
            x %= mod;
        }
        return result;
    }

    ll str_to_num(string s)
    {
        stringstream pk(s);
        ll num;
        pk >> num;
        return num;
    }

    string num_to_str(ll num)
    {
        return to_string(num);
    }
    // Techniques :
    // divide into cases, brute force, pattern finding
    // sort, greedy, binary search, two pointer
    // transform into graph

    // Experience :
    // Cp is nothing but only observation and mathematics.
    ll solve()
    {
        ll n, k;
        string s;
        cin >> n >> k >> s;
        vector<ll> v(n, 0);
        if (k & 1)
        {
            ll pos_first_one = n - 1;
            for (ll i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    pos_first_one = i;
                    break;
                }
            }
            for (ll i = 0; i < n; i++)
            {
                if (i == pos_first_one)
                {
                    continue;
                }
                if (s[i] == '0')
                {
                    s[i] = '1';
                }
                else
                {
                    s[i] = '0';
                }
            }
            k--;
            v[pos_first_one]++;
        }
        // cout<<"temp s "<<s<<endl;
        ll one = 0, zero = 0;
        vector<ll> v_zero, v_one;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zero++;
                v_zero.pb(i);
            }
            else
            {
                one++;
                v_one.pb(i);
            }
        }
        for (ll i = 0; i + 1 < v_zero.size() && k > 0; i += 2)
        {
            v[v_zero[i]]++;
            v[v_zero[i + 1]]++;
            s[v_zero[i]] = '1';
            s[v_zero[i + 1]] = '1';
            k -= 2;
        }
        if (v_zero.size() & 1 && k > 0)
        {
            v[v_zero.back()]++;
            s[v_zero.back()] = '1';
            s[n - 1] = '0';
            v[n - 1]++;
            k -= 2;
        }
        if (k > 0)
        {
            v[n - 1] += k;
        }
        cout << s << endl;
        printv(v);
        return 0;
    }
};

/*  --------------------MAIN PROGRAM----------------------------*/

int main()
{
    speed;
    /* #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif */
    ll TestCase = 1;
    cin >> TestCase;
    while (TestCase--)
    {
        Codeforces cf;
        cf.solve();
    }
}
/* -----------------END OF PROGRAM --------------------*/
/*
 * stuff you should look before submission
 * constraint and time limit
 * int overflow
 * special test case (n=0||n=1||n=2)
 * don't get stuck on one approach if you get wrong answer
 */