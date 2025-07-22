#include<iostream>
#include<queue>
using namespace std;

// Q-> Sliding Window Maximum
//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // step1-> Process first window
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            int element=nums[i];
            while(!dq.empty() && nums[dq.back()]<element){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // answer of first window
        ans.push_back(nums[dq.front()]);

        // step2-> process remaining window
        for(int i=k;i<nums.size();i++){
            // removal 
            if(dq.front()<i-k+1){
                dq.pop_front();
            }
            //addition
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            // Store ans
            ans.push_back(nums[dq.front()]);

        }
        return ans;
    }
};

int main(){

}