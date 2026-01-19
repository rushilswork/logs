#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// instead of using stack we can use vector
void TCSOLVE(){
    ll n;
    cin >> n;
    vector<int> v;
    for(int i =0 ;i<n;i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> ans;
    for(int i =0 ;i<n;i++){
        if(v[i] > 0){
            ans.push_back(v[i]);
        }
        else{
            // left should be +ve as they move forward and collision happens with -ve as they come left side
            if(!ans.empty() && ans.back() > 0){
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(v[i])){
                    ans.pop_back();
                }

                if(!ans.empty()){
                    if(ans.back() == abs(v[i])){
                        ans.pop_back();
                        continue;
                    }
                    if(ans.back() > abs(v[i])){
                        continue;
                    }
                }
            }
            ans.push_back(v[i]);
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

    stack<int> s;
    for(int i =0 ;i<n;i++){
        if(v[i] > 0){
            s.push(v[i]);
        }
        else{
            if(s.top() > 0){
                while(!s.empty() && s.top() < abs(v[i])){
                    s.pop();
                }
                if(!s.empty()){
                    if(s.top() == abs(v[i])){
                        s.pop();
                        continue;
                    }
                    if(s.top() > abs(v[i])){
                        continue;
                    }
                }
            }
            s.push(v[i]);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(int i = ans.size() - 1;i>=0;i--){
        cout << ans[i] << " ";
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