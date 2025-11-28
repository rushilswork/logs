#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Implementation of queue using arrays

int start = -1;
int back = -1;

int fixsize = 5;
int isEmpty = 1;
int size = 0;
int arr[5];

void push(int x){
    if(start == -1 && back == -1){
        start++;
    }
    if(size == 10){
        return;
    }
    back = (back + 1) % fixsize;
    arr[back] = x;
    if(isEmpty){
        isEmpty = 0;
    }
    size++;
}

void pop(){
    if(size == 0){
        return;
    }

    start = (start + 1) % fixsize;
    size--;
    if(size == 0){
        isEmpty = 1;
    }
}

int Empty(){
    return isEmpty;
}

void TCSOLVE(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    pop();
    pop();

    push(6);
    push(7);

    while(!Empty()){
        cout << arr[start] << " ";
        pop(); 
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
