#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n,X;
    cin >> n >> X;
    vector<int> v;
    for(int i = 0;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int andofv = v[0];
    for(auto x: v){
        andofv &= x;
    }

    if(andofv > X){
        cout << 0 << endl;
        return;
    }

    int ans = v.size();
    for(int i = 31;i>=0;i--){
        if((X >> i)&1){
            // as the andofv is less than x, we need to atleast try to make it equal to
            // already set bit in X, need to be also set in andofv
            // to make it greater than X , we need to set those bit in andofv which are unset in X
            andofv|=(1 << i);
            // dont worry about the number count we have to change when we make this set
            // cuz later in the same number some other bit need to be changed
            // also we need to consider the count only when the xor is > X, it will be greater only when we make the unset bit set on comparing with X
            // we'll play the game only on unset bits, not on the set bits, 
            // so here we set directly in andofv so that the number will be equal to X atleast eventually


            // simple idea is:
            // make sure andofv and X are same and now set unset bits to make one greater than other, during this process we need to find number of operations and take the min one
        }
        else{   
            int temp = andofv;
            temp|=(1<<i);
            int cnt = 0;
            // we are making the unset bit set in temp, not directly in andofv, because outcomes are processed on unset bits, while andofv is in the process of becoming the same value as X
            // now the value will be definately greater than X
            // so we need to check which are bits are unset at this position, you can perform & and check if the position bit is set or unset
            for(auto x: v){
                // find set bits, N - setbits = unsetbits
                if((temp&x) == temp){
                    cnt++;
                }
            }
            ans = min(ans, (signed)v.size() - cnt);
        }
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
