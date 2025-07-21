#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void revereRec(queue<int> &q){
    if(q.empty()){
        return;
    }
    int val=q.front();
    q.pop();
    revereRec(q);
    q.push(val);
    
}
void ReverseQueueST(queue<int>&q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
void printQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    // revereRec(q);
    ReverseQueueST(q);
    printQueue(q);

    return 0;
}