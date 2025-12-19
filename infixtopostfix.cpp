#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

//a+b*(c^d-c)
void infixtopostfix(string &s){
    map<char,int> m = {
        {'^',3},
        {'*',2},
        {'/',2},
        {'+',1},
        {'-',1},
    };

    stack<char> stc;
    string letters="abcdefghijklmnopqrstuvwxyz";
    string ans="";
    for(int i =0 ;i<s.length();i++){
        // operands
        if(letters.find(s[i])!=string::npos){
            ans+=s[i];
        }
        // operators
        else{
            if(stc.empty()){
                stc.push(s[i]);
            }
            else{
                // in stack always the high priority symbol should be present, so if theres any less priority one is about to be added to stack check and remove all the highpriorty ones and add them to ans
                while(!stc.empty() && s[i] != '(' && s[i] != ')' && m[s[i]] <= m[stc.top()]){
                    ans+=stc.top();
                    stc.pop();
                }
                
                // when encountered ')' make sure to remove all the ones in the stack until you encounter 
                if(s[i] == ')'){
                    while(!stc.empty() && stc.top() !='('){
                        ans+=stc.top();
                        stc.pop();
                    }
                    // safety check
                    if(stc.top() == '('){
                        stc.pop();
                    }
                    continue;
                }
                // after removing add the current one
                // in the same line the case where high priority ones will be handled
                stc.push(s[i]);
                // in the same line the case where '(' will be handled  
            }
        }
        // stack<char> temp = stc;
        // while(!temp.empty()){
        //     cout << temp.top() << " ";
        //     temp.pop();
        // }
        
    }
    while(!stc.empty()){
        ans+=stc.top();
        stc.pop();
    }
    s = ans;
}

//a*(b+c)/d
// stack - *(+
// ans  - abc+
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
