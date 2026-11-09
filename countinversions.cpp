#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int Count(int low,int right, int mid, vector<int>&v){
    int l = low;
    int r = mid;

    int cnt = 0;
    vector<int> temp;
    while(l < mid && r < right){
        if(v[l] <= v[r]){
            temp.push_back(v[l]);
            l++;
        }
        else if(v[l] > v[r]){
            cnt+=(mid - l);  
            temp.push_back(v[r]);
            r++;
        }
    }

    while(l < mid){
        temp.push_back(v[l]);
        l++;
    }
    while(r < right){
        temp.push_back(v[r]);
        r++;
    }

    int k = 0;
    while(low < right){
        v[low] = temp[k++];
        low++;
    }

    return cnt;
}

int CountInversions(int low, int right, vector<int> &v){
    int cnt = 0;
    
    if(right-low <= 1){
        return cnt;
    }

    int mid = low + (right - low)/2;
    cnt += CountInversions(low,mid,v);
    cnt += CountInversions(mid,right, v);
    cnt += Count(low,right,mid,v);
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
    
    cout << CountInversions(0,n,v);
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
