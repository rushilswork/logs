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

    // this approach doesnt print how many min step to reach the last idx, it just tells if its possible to reach or not
    int maxreach = 0; // intial idx is the max reach for the first time
    for(int i =0 ;i<n;i++){
        if(i > maxreach){
            cout << "false" << endl;
            return;
        }
        maxreach = max(maxreach,v[i] + i);
    }

    cout << "true" << endl;
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
