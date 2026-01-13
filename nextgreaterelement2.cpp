
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

    vector<int> ans(n,-1);
    stack<int> s;
    // assume we are maintaining 2x size of array
    for(int i = 2*n - 1;i>=0;i--){
        while(!s.empty() && v[i%n] >= s.top()){
            s.pop();
        }
        if(!s.empty()){
            ans[i%n] = s.top();
        }
        s.push(v[i%n]);
    }

    for(auto x: ans){
        cout << x << " ";
    }
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



/*

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

    vector<int> ans(n,-1);

    nextgreaterelement 2 - > if didn't find greater on the right, check in circular fashion

    for this circular check we double the array with the same elements
    x y z x y z

    instead of maintaining the 2x size of array, we just assume and play with indexes


    for(int i=0;i<n;i++){
        for(int j=i+1;j<i+n;j++){
            if(v[i] < v[j%n]){
                ans[i] = v[j%n];
                break;
            }
        }
    }

    for(auto x: ans){
        cout << x << " ";
    }

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



*/