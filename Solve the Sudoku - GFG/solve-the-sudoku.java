//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver_class
{
    public static void main(String args[])
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int grid[][] = new int[9][9];
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                grid[i][j] = sc.nextInt();
            }
            
            Solution ob = new Solution();
            
            if(ob.SolveSudoku(grid) == true)
                ob.printGrid(grid);
            else
                System.out.print("NO solution exists");
            System.out.println();
            
        }
    }
}




// } Driver Code Ends


//User function Template for Java

class Solution
 
{
    public static boolean isSafe(int arr[][],int row,int col,int digit){
for(int i=0;i<9;i++){
if(arr[i][col]==digit){
return false;
}
}
for(int i=0;i<9;i++){
if(arr[row][i]==digit){
return false;
}
}
int sr = (row/3)*3;
int sc = (col/3)*3;
for(int i=sr;i<sr+3;i++){
for(int j=sc;j<sc+3;j++){
if(arr[i][j]==digit){
return false;
}
}
}
return true;
    }
    //Function to find a solved Sudoku. 
    public static boolean solve(int arr[][],int row,int col){
//base condition
if(row==9 && col==0){
return true;
}
int nrow=row,ncol =col+1;
if(col+1==9){
nrow=row+1;
ncol=0;
}
if(arr[row][col]!=0){
return solve(arr,nrow,ncol);
}
for(int digit=1;digit<=9;digit++){
if(isSafe(arr,row,col,digit)){
arr[row][col]=digit;
if(solve(arr,nrow,ncol)){
return true;
}
arr[row][col]=0;
}
}
return false;
}
    static boolean SolveSudoku(int grid[][])
    {
        // add your code here
        return solve(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    static void printGrid (int grid[][])
    {
        // add your code here
        int n=grid.length;
        int m=grid[0].length;
        for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
   System.out.print(grid[i][j]+" ");
}
}
        
        
    }
}