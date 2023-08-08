#User function Template for python3

class Solution:
    def MedianOfArrays(self, a, b):
        a+=b
        a.sort()
        n = len(a)
        if n%2 == 0:
            val = ((a[n//2]+a[(n//2)-1])/2)
            if int(val)*2 != val *2:
                return  val
            else:
                return int(val)
        else:
            return (a[n//2])


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    tcs=int(input())

    for _ in range(tcs):
        m = input()
        arr1=[int(x) for x in input().split()]
        n = input()
        arr2=[int(x) for x in input().split()]
        
        
        ob = Solution()
        print(ob.MedianOfArrays(arr1,arr2))

# } Driver Code Ends