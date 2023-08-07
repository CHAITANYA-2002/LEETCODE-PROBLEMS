//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

bool issafe(int row,int col,vector<vector<int>> st,int n){
       int inrow = row;
       int incol = col;
       while(row>=0 && col>=0){
           if(st[row][col]==1)return false;
           row--;
           col--;
       }
       row = inrow;
       col = incol;
      
        while(col>=0){
           if(st[row][col]==1)return false;
           col--;
        }
        col = incol;
         while(row<n && col>=0){
           if(st[row][col]==1)return false;
           row++;
           col--;
       }
       return true;
   }
   void hello(int col ,vector<vector<int>> &ans,int n,vector<int> &ko , vector<vector<int>>&board){
       if(col==n){
           ans.push_back(ko);
            return;
       }
       for(int i=0;i<n;i++){
           if(issafe(i,col,board,n)){
               board[i][col]=1;
               ko.push_back(i+1);
               hello(col+1,ans,n,ko,board);
               board[i][col]=0;
               ko.pop_back();
           }
       }
   }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<int> ko;
        hello(0,ans,n,ko,board);
        return ans;
    }
    
    
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends