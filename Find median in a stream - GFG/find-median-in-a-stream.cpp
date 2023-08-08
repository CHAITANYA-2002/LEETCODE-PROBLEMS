//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends



class Solution
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    { 
        // Insert the element into the appropriate heap to maintain the balance.
        if (maxHeap.empty() || x <= maxHeap.top())
            maxHeap.push(x);
        else
            minHeap.push(x);

        // Balance the heaps if needed.
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
         int maxSize = maxHeap.size();
        int minSize = minHeap.size();

        // If the difference in sizes of heaps is more than 1, we need to balance them.
        if (abs(maxSize - minSize) > 1)
        {
            if (maxSize > minSize)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
         int maxSize = maxHeap.size();
        int minSize = minHeap.size();

        // If the total number of elements is even, return the average of the middle two elements.
        if (maxSize == minSize)
            return (maxHeap.top() + minHeap.top()) / 2.0;

        // Otherwise, return the top element of the larger heap (which contains the median).
        return (maxSize > minSize) ? maxHeap.top() : minHeap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends