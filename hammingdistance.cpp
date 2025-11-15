#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    int hammingdistance = 0;


    for(int i =0 ;i<32;i++){
        int cnt = 0;
        for(int j =0 ;j<n;j++){
            if((v[j] >> i) & 1 == 1){
                cnt++;
            }
        }
        // every setbit makes up a pair with the unsetbit
        hammingdistance+=(cnt*(n - cnt));
    }

    cout << hammingdistance << endl;
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
