#include<iostream>
#include<queue>
using namespace std;

// Q->Interleave the First Half of the Queue with Second Half
// Given a Queue of even size . Your task is to rearrange the queue by interleaving its first half with the second half.
// Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
// In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again 2nd element from the first half and then second element from the 2nd half and so on....

// Input: q = [2, 4, 3, 1]
// Output: [2, 3, 4, 1]

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        int size=q.size();
        queue<int> secondq;
        for(int i=0;i<size/2;i++){
            int element=q.front();
            q.pop();
            secondq.push(element);
        }
        queue<int> finalq;
        while(!q.empty()){
            finalq.push(secondq.front());
            secondq.pop();
            finalq.push(q.front());
            q.pop();
        }
        return finalq;
        
    }
};