#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    // if there is only one set bit to find its position we have to use log base 2
    // the reason is if we observe the representation of binary -> decimal conversion we write it in the form of powers of 2
    // so to get the power we can use log and adjust the position by adding 1

    // this check make sures that only one set bit is present
    if(!(n&(n-1))){
        cout << floor(log(n)) + 1 << endl;
    }
    else{
        cout << "has more than 1 set bit" << endl;
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
