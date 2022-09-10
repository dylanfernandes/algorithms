using System;
/* Write a function:

class Solution { public int solution(int[] A); }

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000]. */

class Solution {
    public int solution(int[] A) {
        int desired = 1;
        if(A.Length == 0)
            return desired;
        Array.Sort(A);

        int? last = null;
        foreach(int num in A) {
            if(num > 0 && num != last) {
                if(num == desired) {
                    last = num;
                    desired++;
                }
                else
                    break;
            }
        }
        return desired;
    }
}
