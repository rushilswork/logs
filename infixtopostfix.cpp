#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int prec(char c){
    if(c == '^'){
        return 3; 
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infixtopostfix(string &s){
    string ans = "";
    stack<int> stc;
    for(int i = 0;i<s.length();i++){
        char c = s[i];
        // for operands
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            ans+=c;
        }
        else if(c == '('){
            stc.push(c);
        }
        else if(c == ')'){
            while(!stc.empty() && stc.top() != '('){
                ans+=stc.top();
                stc.pop();
            }

            // safety check

            if(stc.top() == '('){
                stc.pop();
            }
        }
        // for operators
        else{
            while(!stc.empty() && prec(c) <= prec(stc.top())){
                ans+=stc.top();
                stc.pop();
            }
            stc.push(c);
        }
    }

    // the operators remained in the stack need to be added back into the ans
    while(!stc.empty()){
        ans+=stc.top();
        stc.pop();
    }
    s = ans;
}

void TCSOLVE(){
    string s;
    cin >> s;
    infixtopostfix(s);
    cout << s << endl;
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
