#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


void postfixtoinfix(string &s){
    string ans="";
    stack<string> stc;
    for(int i =s.length() - 1 ;i>=0;i--){
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
                string temp = '(' + b + c + a + ')';
                stc.push(temp);
            }
        }
    }

    stringstream ss;
    ss << stc.top();
    ss >> ans;
    cout << ans << endl;

}
void TCSOLVE(){
    string s;
    cin >> s;
    postfixtoinfix(s);
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
