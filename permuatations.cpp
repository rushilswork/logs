#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void permuatations1(vector<int>&v,vector<int>ans, map<int,bool> m, int i){

    if(ans.size() == v.size()){
        for(auto x: ans){
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    if(i == v.size()){
        return;
    }

    if(!m[v[i]]){
        m[v[i]] = true;
        ans.push_back(v[i]);
        permuatations1(v,ans,m,0);
        // once an element is selected, look for the other element to be placed at state x, from index 0 to n - 1
        ans.pop_back();
        m[v[i]] = false;
    }

    // if the element is present then go for other element like unpick this and jump on to other element
    permuatations1(v,ans,m,i + 1);
}


void permuatations2(vector<int>&v, int state, int i){

    if(state == v.size() && i == v.size()){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    if(i == v.size()){
        return;
    }

    swap(v[state],v[i]);
    permuatations2(v,state + 1, state + 1);
    swap(v[state],v[i]);

    permuatations2(v,state,i + 1);
}

void permutations3(vector<int>&v, int i){

    if(i == v.size()){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    for(int idx = i;idx<v.size();idx++){
        swap(v[i],v[idx]);
        permutations3(v,i+1);
        swap(v[i],v[idx]);
    }
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

    map<int,bool> m;
    vector<int> ans;
    // permuatations1(v, ans, m, 0);
    permuatations2(v,0,0);
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
