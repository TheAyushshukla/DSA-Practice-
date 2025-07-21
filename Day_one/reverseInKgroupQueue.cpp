#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseK(queue<int>&q,int k,int count){
    if(count>=k){
        stack<int>st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
            
        }
        for(int i=0;i<k;i++){
            int element =st.top();
            
            st.pop();
            q.push(element);
        }
        reverseK(q,k,count-k);


    }else{
        for(int i=0;i<count;i++){
            int element=q.front();
            q.pop();
            q.push(element);
        }

    }

}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(35);
    q.push(38);
    q.push(40);
    q.push(42);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    int k=3;
    int count=q.size();
    reverseK(q,k,count);
    while(!q.empty()){
        int element=q.front();
        cout<<element<<" ";
        q.pop();   
    }
    return 0;
}