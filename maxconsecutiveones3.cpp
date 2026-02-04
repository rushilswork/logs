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

    // sliding window

    int cnt =0;
    int l =0;
    int r = 0;
    int len = 0;
    int maxlen = INT_MIN;
    while(r < n){
        if(v[r] == 0){
            cnt++;
        }

        // in case if cnt > k, shrink 
        while(cnt > k){
            if(v[l] == 0){
                cnt--;
            }
            l++;
        }


        len = r - l + 1;
        maxlen = max(maxlen,len);
        r++;
    }

    cout << maxlen << endl;
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}


/*
    optimal - 1
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


    int len = 0;
    int maxlen = INT_MIN;
    map<int,int> m;
    int cnt = 0;
    for(int i =0 ;i<n;i++){
        if(v[i] == 0){
            cnt++;
        }
        // at every step check, if the k zero's subarray exists with prefix sum logic
        if(cnt > k && m.find(cnt - k)!=m.end()){
            // if exists
            // cout << m[cnt - k] << " ";
            len = i - m[cnt - k];// subarray length
        }
        else if(cnt <= k){
            len = i + 1;
        }

        maxlen = max(maxlen,len);
        
        if(m.find(cnt)==m.end()){
            m[cnt] = i;
        }
        // prefix sum until index in map<sum,index>
    }
//1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
    cout << maxlen << endl;
}
int main(){
    ll n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    n = 1;
    while(n--){
        TCSOLVE();
    }
}

*/