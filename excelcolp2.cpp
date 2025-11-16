#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;


    // 26 ^ 1 x 1 + 26 ^ 0 x 25 - AY - 51
    int ans = 0;
    int mul26 = 1;
    for(int i =s.length() - 1;i>=0;i--){
        ans+=(s[i] - 'A' + 1)*mul26;
        mul26*=26;
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
