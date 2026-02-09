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
    while(r < n){
        if(v[r]&1){
            subcnt++;
        }
        while(subcnt > k){
            if(v[l]&1){
                subcnt--;
            }
            l++;
        }
        // while the sum is sum <= k, calculate the subarrays, basically we are building the count internally we are applying divide and conquer logic not techinically but logically, 
        /*
            1 0 0 1 1 0 
            in the subarray
            1 -> 1 
            1 0 -> total of 3 => 1 , 1 0, 0
            1 0 0 -> total of 6 => 1, 1 0, 1 0 0 , 0 , 0 0, 0 ( but in this few of them we already calculated in the previous step )
            so when you reach at a particular index, check how many subarrays does this index add up to previous subarrays
        */
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}

void TCSOLVE(){
    ll n;cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;

    cout << utilityfunction(v,k) - utilityfunction(v,k-1) << endl;
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
