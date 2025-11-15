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
    /*
        int num = (xorv & xorv - 1) ^ xorv;
        or
        int num = (xorv & ~(xorv - 1));

        1011100
        ~1011100 = 1011000

        1011100
        ~1011000

        1011100
        0100111

        now as we want thr right most bit, we know if we do -1 borrow will be done from the right most bit and doing & will remove the right most bit

        from that thinking, now we want only thr rightmost bit and rest 0
        for others to be zeros its more like thinking removing them so we can remove them by doing ~ and &

        (n & ~(n - 1)) (or) (n & (n - 1) ^ n)

        and also once we get only the right most bit and now if we have to check if the same position bit is set in other numbers we dont really have to travers everyposition and check, instead do a & ooperation 

        v[i] & xorv;
    */


    // for (int i = 0; i < 32; i++)
    // {
    //     if ((num >> i) & 1 == 1)
    //     {
    //         pos = i;
    //         break;
    //     }
    // }
    // for (int j = 0; j < n; j++)
    // {
    //     if ((v[j] >> pos) & 1 == 1)
    //     {
    //         a ^= v[j];
    //     }
    //     else
    //     {
    //         b ^= v[j];
    //     }
    // }

    for (int j = 0; j < n; j++)
    {
        // as xorv has only the right most bit set, this check if the same position bit is set in other numners aswell, if no doing & will results in 0 else > 0
        if (v[j] & xorv)
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
