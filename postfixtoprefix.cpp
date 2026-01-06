#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


void postfixtoprefix(string &s){
    string ans="";
    stack<string> stc;
    for(int i =0;i<s.length();i++){
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            stc.push(string(1,c));
        }
        // operator
        else{
            if(stc.size() >= 2){
                string b = stc.top();
                stc.pop();
                string a = stc.top();
                stc.pop();
                string temp = string(1,c) + a + b;
                stc.push(temp);
            }
        }
    }

    cout << stc.top() << endl;

}
void TCSOLVE(){
    string s;
    cin >> s;
    postfixtoprefix(s);
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
