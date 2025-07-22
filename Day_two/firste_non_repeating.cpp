#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

//Q->Stream First Non-repeating


// Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

// NOTE:
// 1. You need to find the answer for every i (0 <= i < n)
// 2. In order to find the solution for every you need to consider the string from starting position till the ith position.

// Input: s = "aabc"
// Output: "a#bb"
 

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        unordered_map<char,int> freq;
        queue<int> q;
        string ans="";
        
        
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
            q.push(s[i]);
            
            while(!q.empty()){
                
                if(freq[q.front()]==1){
                    ans.push_back(q.front());
                    break;
                }
                else{
                    q.pop();
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}