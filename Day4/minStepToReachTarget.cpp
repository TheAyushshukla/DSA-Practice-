#include<iostream>
#include<queue>
using namespace std;

//Q-> Steps by Knight

// Given a square chessboard of size (n x n), the initial position and target postion of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

// Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

//Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
// Output: 1

class Solution {
  public:
    bool explore(pair<int,int>&front,pair<int,int>&dest, queue<pair<int,int>> &q,vector<vector<bool>> &vis,int &N){
        int x[]={-1,-1,1,1,2,2,-2,-2};
        int y[]={2,-2,2,-2,1,-1,1,-1};
        
        for(int i=0;i<8;i++){
            int newX=front.first+x[i];
            int newY=front.second+y[i];
            
            if(newX <0 || newX >=N || newY<0 || newY>=N || vis[newX][newY]) 
                continue;
            
            if(make_pair(newX,newY)==dest) return true;
            
            q.push({newX,newY});
            vis[newX][newY]=true;
        }
        return false;
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int N) {
        // 1->based Indexing
        pair<int,int> src={knightPos[0]-1,knightPos[1]-1};
        pair<int,int> des={targetPos[0]-1,targetPos[1]-1};
        
        if(src==des) return 0;
        
        queue<pair<int,int>> q;
        q.push(src);
        q.push({-1,-1});
        vector<vector<bool>> vis(N,vector<bool>(N,false));
        vis[src.first][src.second]=true;
        
        int step=1;
        
        while(!q.empty()){
             auto front=q.front();
             q.pop();
             
            if(front==make_pair(-1,-1)){
                step++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                continue;
            }
               if(explore(front, des, q, vis, N)) {
                    return step;
    }
        }
        return -1;
        
    }
};