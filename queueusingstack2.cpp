#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// implementation of queue using stack

// approach 2 optimizing the transfer of elements when a new element is added
// in approach 1 we keep tranfering the elements everytime a new element is added 

stack<int> s1;
stack<int> s2;
stack<int> temp;
int back_ = INT_MAX;

// keep adding them in stack 1 until front back or pop is called
void push(int x){
    s1.push(x);
    back_ = x;
}   

void pop(){
    // if s2 is not empty that means tranfer is already done
    if(!s2.empty()){
        s2.pop();
    }
    // if s2 is empty do the tranfer and pop the element
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
}

int front(){
    // if s2 is not empty that means tranfer is already done
    if(!s2.empty()){
        return s2.top();
    }
    // if s2 is empty do the tranfer and get front element
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    } 
}

int back(){
    if(back_ != INT_MAX){
        return back_;
    }
}

void printqueue(){
    stack<int> temp1 = s1;
    stack<int> temp2 = s2;

    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    // check if there are elements in s1
    // tranfer and print
    while(!temp1.empty()){
        temp2.push(temp1.top());
        temp1.pop();
    }

    while(!temp2.empty()){
        cout << temp2.top() << " ";
        temp2.pop();
    }
    cout << endl;
}
void TCSOLVE(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printqueue();

    cout << front() << endl;
    cout << back() << endl;

    pop();
    pop();

    printqueue();
    
    cout << front() << endl;
    cout << back() << endl;


    push(6);
    push(7);

    printqueue();
    
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
