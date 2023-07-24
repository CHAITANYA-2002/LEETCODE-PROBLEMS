//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void printTriangle(int n) {
        int k = 1;
        while(n--) {
            cout << string(n, ' ') <<  string(k, '*') << "\n";
            k += 2;
        }
    }
   
   
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends