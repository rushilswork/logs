#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }   

    map<int,int> m;
    int l = 0;
    int r = 0;
    int maxlen = INT_MIN;
    while(r < n){
        m[v[r]]++;
        // as we are focusing on length, not on the values in the subarrays like we dont need to print them so, if we get length of 4 on the fly and now we have to strink we dont need to shrink all the way < 4 to 3,2,.. or 1, for now size is 4, we must look for subarray length > 4 i.e, 5 or more, so which satisfies our case

        // while(m.size() > 2){
        if(m.size() > 2){
            m[v[l]]--;
            if(m[v[l]] ==0){
                m.erase(v[l]);
            }
            l++;
        }
        maxlen = max(maxlen,r - l + 1);
        r++;
    }

    cout << maxlen << endl;
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
