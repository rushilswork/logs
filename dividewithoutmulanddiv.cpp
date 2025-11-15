#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll divisor, divident;
    cin >> divisor >> divident;

/*
    int cnt =0 ;
    while(divident >= divisor){
        divident-=divisor;
        cnt++;
    }

    cout << cnt << endl;
*/

// 3 22
// instead of removing 3 once from 22, we try to remove in bulk of 3's 
// 3 x 7 -> 3 x ( 2 ^ 2 + 2 ^ 1 + 2 ^ 0);
// 3 x ans -> as we can represent the ans in sum of powers of 2 so we'll try that

    int ans = 0;
    int pos = 0;
    while(divident >= divisor){
        int chunk = divisor*(1<<pos);
        divident-=chunk;
        ans+=(1 << pos);
        pos++;
    }
    cout << ans << endl;

}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}
