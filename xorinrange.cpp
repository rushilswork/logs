#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int xor1ton(int n){
    int modofn = n%4;

    if(modofn == 0){
        return n;
    }
    else if(modofn == 1){
        return 1;
    }
    else if(modofn == 2){
        return n + 1;
    }
    else if(modofn == 3){
        return 0;
    }   
}
void TCSOLVE(){
    int l,r;
    cin >> l >> r;

    l = xor1ton(l - 1);
    r = xor1ton(r);

    int ans = l^r;
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
