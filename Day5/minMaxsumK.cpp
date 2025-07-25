#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int maxMinSumofSizeK(vector<int>& nums,int k){
    deque<int> q,q2;
    int ans=0;

    for(int i=0;i<k;i++){

        while(!q.empty() && nums[i]>=nums[q.back()]){
            q.pop_back();
        }

        while(!q2.empty() && nums[i]<=nums[q2.back()]){
            q2.pop_back();
        }
        q.push_back(i);
        q2.push_back(i);

    }
    ans+=nums[q.front()]+nums[q2.front()];

    for(int i=k;i<nums.size();i++){

        if(!q.empty() && i-q.front()>=k){
            q.pop_front();
        }
        if(!q2.empty() && i-q2.front()>=k){
            q2.pop_front();
        }

        while(!q.empty() && nums[i]>=nums[q.back()]){
            q.pop_back();
        }
        while(!q2.empty() && nums[i]<=nums[q2.back()]){
            q2.pop_back();
        }    
        q.push_back(i);
        q2.push_back(i);
        ans+=nums[q.front()]+nums[q2.front()];
    }
    return ans;

}
int main(){
    vector<int>v{2,5,-1,7,-3,-1,-2};
    cout<<maxMinSumofSizeK(v,4);
    return 0;
}