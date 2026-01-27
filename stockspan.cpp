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

    stack<int> s;
    for(int i =0 ;i<n;i++){
        if(s.empty()){
            s.push(i);
            cout << i + 1 << " ";
        }
        else{
            while(!s.empty() && v[s.top()] <= v[i]){
                s.pop();
            }
            if(!s.empty()){
                cout << i - s.top() << " ";
            }
            else{
                cout << i + 1 << " " ;
           }
           s.push(i);
        }
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

vector<int> previousgreaterelement(vector<int>&v){
    stack<int> s;
    int n = v.size();
    vector<int> ans(n,-1);
    for(int i =0 ;i<n;i++){
        if(s.empty()){
            s.push(i);
        }
        else{
            while(!s.empty() && v[s.top()] <= v[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }
            s.push(i);
        }
    }
    return ans;
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
    vector<int> ans = previousgreaterelement(v);

    for(int i =0 ;i<n;i++){
        (ans[i] == -1)?cout << (i + 1) << " ":cout << (i - ans[i]) << " ";
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

/*
    ///brute force
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

    for(int i =0 ;i<n;i++){
        int cnt = 0;
        for(int j =i;j>=0;j--){
            if(v[j] <= v[i]){
                cnt++;
            }
            else{
                break;
            }
        }
        cout << cnt << " ";
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