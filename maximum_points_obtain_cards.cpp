#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    int k;
    cin >> k;


    int maxsum = INT_MIN;
    int sum = 0;
    // first take sum of k elements and then keep removing from k elements and keep adding from last total of k elements
    int l = 0, r = n - 1;
    
    // instead of nesting loop, as outloop runs only for k elements sum and then innner loop takes the lead and keep adding elements from back until k dies, you can take the sum of k element intially and run the loop by removing first elements and adding last elements total of k
    while(l < n){
        sum+=v[l];
        // as we are focusing on sum which depends on elements, we cant optimize inner while loop, just like we do for length based problems
        maxsum = max(maxsum,sum);
        if(l + 1 == k){
            while(k > 0 && l >= 0){
                sum-=v[l];
                l--;
                sum+=v[r];
                r--;
                maxsum = max(maxsum,sum);
                k--;
            }
            break;
        }
        l++;
    }

    cout << maxsum << endl;
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
