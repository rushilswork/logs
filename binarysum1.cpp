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
    int k;
    cin >> k;

    // unlike find the length of subarray that should be maximum with sum is k, we use the map for prefix sum logic, where we store the prefix sum and index to find the length, where here we dont store the indexes, we instead store the count of subarrays with sum being prefix sum, what it means is, 
    // suppose --------- in this length of subarray as at every point we check if the total sum - k exists in the map already, like total being 6, where k being 3, 6 - k = 3, so we need to check "how many subarrays with the sum being 3" if there are 3 subarrays in the background with sum 3
    
    map<int,int> m;
    int r = 0;
    int sum =0 ;
    int cnt = 0;
    /*
    
    for cases where the array starts with 0 0 0 0 1, it has 5 subarrays with sum = 1, if we check if sum == 1{ cnt++ }, it wont look back for other 0 cases at the same time if at all we look for cases of these 0's as prefix, so remove else for m[sum - k] case and keep as if,so that 0's like cases will be covered

    */
    while(r < n){
        sum+=v[r];
        if(sum == k){
            cnt++;
        }
        if(m.find(sum - k)!=m.end()){
            cnt+=m[sum - k];
        }
        m[sum]++;
        r++;
    }

    cout << cnt << endl;
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
