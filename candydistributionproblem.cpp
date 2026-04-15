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

    vector<int> left;
    // comparing left neighbours
    left.push_back(1);
    for(int i = 1;i<n;i++){
        if(v[i] > v[i - 1]){
            left.push_back(left[i - 1] + 1);
        }
        else{
            left.push_back(1);
        }
    }

    int prev = 1;
    int right = 1; // curr // comparing right neighbours

    int sum = left[n - 1];
    for(int i = n - 2;i>=0;i--){
        if(v[i] > v[i + 1]){
            right = prev + 1;
        }
        else{
            right = 1;
        }
        prev = right;
        sum += max(left[i], right);
    }


    cout << sum << endl;
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
