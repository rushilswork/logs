#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll divisor, divident;
    cin >> divident >> divisor;

    int sign = 1;
    if(divisor < 0 || divident < 0){
        sign = 0;
        divisor = abs(divisor);
        divident = abs(divident);
    }
/*
    int cnt =0 ;
    while(divident >= divisor){
        divident-=divisor;
        cnt++;
    }

    cout << cnt << endl;


    22 3
    instead of removing 3 once from 22, we try to remove in bulk of 3's 
    3 x 7 -> 3 x ( 2 ^ 2 + 2 ^ 1 + 2 ^ 0);
    3 x ans -> as we can represent the ans in sum of powers of 2 so we'll try that


    34 3 - 
    3 x 11 - 3 x ( 1 0 1 1 );


    3 x 2 ^ 3 + 3 x 2 ^ 1 + 3 x 2 ^ 0;
    3 x 8 + 3 x 2 + 3 x 1
   
    so look for the number of divisors's that we can remove from the divident first
    basically that should be the max of 3 x ( 2 ^ x )
*/

    int ans = 0;
    int pos = 0;
    while(divident >= divisor){
        int chunk = divisor*(1 << pos);
        if(divident > chunk){
            pos++;
            continue;
        }
        pos--;
        ans+=(1 << pos);
        divident-=divisor*(1 << pos);
    }
    
    if(sign){
        cout << ans << endl;    
    }
    else{
        cout << -1*ans << endl;
    }
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
