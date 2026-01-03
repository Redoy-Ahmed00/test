#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl "\n"
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define rrep(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long ll;
typedef vector <int> vi;
typedef vector <double> vd;
typedef vector <ll> vll;

void solve()
{
    ll n;
    cin >> n;

    set<ll> s;
    bool has = true;;
    while(n != 1)
    {
        if(s.find(n) != s.end())
        {
            has = false;
            break;
        }
        s.insert(n);
        ll sum = 0;
        while(n != 0)
        {
            ll tmp = n%10;
            n = n/10;
            sum += tmp*tmp;
        }
        n = sum;
    }

    if(has)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}

int main ()
{
    optimize();
              
    int t = 1;
    //cin >> t;

    while(t--)
        solve();
        
    return 0;
}