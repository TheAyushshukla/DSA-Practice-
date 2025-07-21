#include<iostream>
#include<queue>
using namespace std;

// Q->First negative in every window of size k
// Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.

// Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
// Output: [-8, 0, -6, -6]

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<int> q;
        vector<int> ans;
        // step 1 -> process first window 
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                q.push_back(i);
            }
        }
        
        // step 2 -> Process remaining -> ans,removal, addition
        
        for(int i=k;i<arr.size();i++){
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                int element=arr[q.front()];
                ans.push_back(element);
            }
            // removal
            if(!q.empty() && i-q.front()>=k){
                q.pop_front();
            }
            // addition
            if(arr[i]<0){
                q.push_back(i);
            }
            
        }
        
        // step ->3 last window process manually 
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            int element=arr[q.front()];
            ans.push_back(element);
        }
        return ans;
        
    }
};