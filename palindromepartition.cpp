#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


bool ispalindrome(string s){
    for(int i =0 ;i<s.length();i++){
        if(s[i] != s[s.length() - i - 1]){
            return false;
        }
    }

    return true;
}
void partitionpalindrome(string s, int i, vector<string> v){

    // i is starting index palindrome substring
    if(i == s.length()){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // from i begin the starting index you have j options to choose which are valid ofcourse, once substring from i - j is made, next starting index would be from j + 1
    for(int j = i;j<s.length();j++){
        string temp = s.substr(i,j - i + 1);
        if(!ispalindrome(temp)){
            continue; 
        }
        v.push_back(temp);
        // index // number of characters
        partitionpalindrome(s,j + 1, v);
        v.pop_back();
    }
}
void TCSOLVE(){
    string s;
    cin >> s;
    
    vector<string> v;
    partitionpalindrome(s, 0, v);
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
