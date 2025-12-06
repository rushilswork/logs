#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Implementation of stack using queue

queue<int> q;

void push(int x){
    q.push(x);
    int s = q.size();
    // all the elements in front of x should be placed next of x
    // 1 2 3 4

    /*
        1

        2
        1 - 2 bring 1 and place after 2
        2 - 1

        3
        2 - 1 - 3 bring 2 and 1 and place next to 3
        3 - 2 - 1

        so thet while printing we get the feel as if its the stack

    */
    for(int i = 0;i<s-1;i++){
        q.push(q.front());
        q.pop();
    }
}


void pop(){
    q.pop();
}

int top(){
    return q.front();
}
void TCSOLVE(){
    push(1);        
    push(2);        
    push(3);        
    push(4);        
    push(5);        

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
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
