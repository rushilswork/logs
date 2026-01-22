#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s;
    cin >> s;
    int k;
    cin >> k;

    if(k == s.length()){
        cout << "0" << endl;
        return;
    }
    stack<int> st;
    for(int i =0 ;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            while(!st.empty() && k > 0 && st.top() - '0' > s[i] - '0'){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
    }

    while(k > 0){
        st.pop();
        k--;
    }

    if(st.empty()){
        cout << "0" << endl;
        return;
    }

    
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    // remove zeroes at front, you can do it after reversing the string and then removing from front, but it is better to remove from the ans before reversing

    // we are removing the zeroes that are going to be at front after reversing
    while(ans.size() > 0 && ans.back() == '0'){
        ans.pop_back();
    }

    // if all zeroes, it will be empty

    if(ans.empty()){
        cout << "0" << endl;
        return;
    }

    reverse(ans.begin(),ans.end());

    cout << ans << endl;

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
