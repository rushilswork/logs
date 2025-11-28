#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// implementation of queue using linked list

struct node{
    int data;
    struct node* next;
};

bool isEmpty = true;
struct node* front = NULL;
struct node* back = NULL;

void push(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(back == NULL){
        back = newnode;
        front = newnode;
        isEmpty = false;
    }    
    else{
        back->next = newnode;
        back = back->next;
    }
}

void pop(){
    if(front == NULL){
        return;
    }
    struct node* tmp = front;
    front = front->next;
    tmp->next = NULL;
    delete tmp;
    if(front == NULL){
        isEmpty = true;
    }
}

bool Empty(){
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
    pop();
    while(front!=NULL){
        cout << front->data << " ";
        front = front->next;
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
