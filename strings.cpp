#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void TCSOLVE(){
    string s1 = "rushil pillamari";   
    string s2 = s1;
    string s3(s1);
    string s4("rushil pillmari");   
    string s5(5,'a');   
    string s6(s1.begin(),s1.end());
    // string s7(s1,7); // pillamari only in constructor it is possible for s, where for literal everywhere it is possible
    string s7(s1,7,5); // pilla // string, starting point and number of characters
    
    // ignore val, #chars

    s7.assign(7,'a');
    s7.assign(s1);  
    s7.assign(s1,7,5);
    s7.assign(s1.begin(),s1.end());
    s7.assign("rushil pillamari");
    // s7.assign("rushil pillamari",7);// string literal and no. of characters // mostly ignore this
    s7.assign("rushil pillamari",7,5);


    s7.insert(s7.begin(),'a');
    s7.insert(s7.begin(),7,'a');
    s7.insert(s7.begin(),s1.begin(),s1.end());
    
    s7.insert(0,7,'a'); 
    s7.insert(0,s1);
    s7.insert(0,s1,7,5);
    s7.insert(0,"rushil pillamari");
    // s7.insert(0,"rushil pillamari",7);
    s7.insert(0,"rushil pillamari",7,5);

    s7.append(7,'a');
    s7.append(s1);
    s7.append(s1,7,5);
    s7.append(s1.begin(),s1.end());
    s7.append("rushil pillamari");
    // s7.append("rushil pillamari",7);
    s7.append("rushil pillamari",7,5);

    s7.replace(7,5,"nidhi pilla");

    string s8(s1,7);
    // cout << s8 << endl;
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
