#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE()
{
    ll n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int xorv = 0;
    for (int i = 0; i < n; i++)
    {
        xorv ^= v[i];
    }

    int a = 0;
    int b = 0;

    int pos = 0;
    int num = (xorv & xorv - 1) ^ xorv;
    for (int i = 0; i < 32; i++)
    {
        if ((num >> i) & 1 == 1)
        {
            pos = i;
            break;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if ((v[j] >> pos) & 1 == 1)
        {
            a ^= v[j];
        }
        else
        {
            b ^= v[j];
        }
    }

    cout << a << " " << b << endl;
}
int main()
{
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while (n--)
    {
        TCSOLVE();
    }
}
