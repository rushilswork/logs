#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// implementation of queue using stack

stack<int> s;
stack<int> temp;
int back_ = INT_MAX;

void push(int x){
    if(s.empty()){
        s.push(x);
    }
    else{
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }

    back_ = x;
}   

void pop(){
    s.pop();
}

int front(){
    return s.top();
}

int back(){
    if(back_ != INT_MAX){
        return back_;
    }
}

void TCSOLVE(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);


    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    cout << endl;
    cout << front() << endl; 
    cout << back() << endl;
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
