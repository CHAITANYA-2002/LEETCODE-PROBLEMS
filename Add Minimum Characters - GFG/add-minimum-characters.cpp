//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
  
int addMinChar(string str) {
    int n = str.length();
    string revStr = str;
    reverse(revStr.begin(), revStr.end()); // reverse the string

    string concat = str + "$" + revStr;
    int lps[2*n+1]; // array to store the longest prefix suffix values

    // calculate the LPS array
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < 2*n+1) {
        if (concat[i] == concat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
             else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return n - lps[2*n]; // return the number of characters to be added
}
};




//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends