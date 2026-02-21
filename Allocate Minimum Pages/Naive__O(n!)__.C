
#include <limits.h>

int sumof(int arr[],int s,int e){
    int sum = 0;
    
                                                            // sum from s to e-1
    for(int i=s;i<e;i++){
        sum += arr[i];
    }
    return sum;
}   
 
 
int findPages(int arr[], int n, int k) {
            
    if(k > n) return -1;                                    // students > books → not possible
    
    if(k == 1)                                                         // only 1 student
        return sumof(arr,0,n);                                             // gets all books
    
    if(n==1)                                                           // only 1 book
        return arr[0];
            
    int res = INT_MAX;                                           // store minimum answer
                                                
    for(int i=1;i<n;i++){                                                              // try every partition
        
                                                                      // first i books → k-1 students
                                                                      // rest books → last student
        
        int curr = max(findPages(arr,i,k-1),
                       sumof(arr,i,n));                                                      // max load
        
        res = min(res,curr);                                                     // take minimum of max
    }   
    
    return res;
}



//////////////////////////////////////////////////////////

We need to choose (k-1) cuts out of (n-1) cuts shown above

Total ways:
_________________________________________
|                                       |
|            n-1                        |
|                C                      |
|                  k-1                  |
|_______________________________________|

Allocate Minimum Pages
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.

Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i], k ≤ 103

