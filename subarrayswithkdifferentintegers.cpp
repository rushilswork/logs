#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int utilityfunction(vector<int>&v,int k){
    if(k == -1){
        return 0;
    }
    int n = v.size();
    int l = 0;
    int r = 0;
    int subcnt = 0;
    int cnt = 0;
    map<int,int> m;
    while(r < n){
        m[v[r]]++;
        while(m.size() > k){
            m[v[l]]--;
            if(m[v[l]] == 0){
                m.erase(v[l]);
            }
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}

void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;
    // optimizing with sliding window logic ( cnt <= k ) - (cnt <= k - 1 or cnt < k)

    // whenever you feel like the subarrays are missing out through prefix sum/cnt logic or with sliding window logic we apply (<=k)-(<k or <=k-1)
    cout << utilityfunction(v,k) - utilityfunction(v,k-1);

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
