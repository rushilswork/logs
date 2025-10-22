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

    // i is state more like ith partitional palindrome substring
    if(i == s.length()){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    // for one state ( one palindrome substring ) we have many options to parition in the string, we dont know how many states it could take, we'll try all possibilities until we reach the end of the string , max states could be length of string
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
