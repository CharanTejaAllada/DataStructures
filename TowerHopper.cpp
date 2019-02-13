/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

//This is a greedy approach for this problem which solves in O(n), where 'n' is number of towers to hop or size of array.
//Note: We calculate the next optimal jump using "calNextPos". Then we goto that step and decide next optimal move.
//Next optimal move is calculated based on which tower gives us maximum range. All the others will be ignored because the range they yield is
//already subset of our maximum range from the current position. 
//Note: We might not make a max jump available from the optimal positon we get. It is where most people gets confused.

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int size = nums.size();
        int target = size-1;
        int Orgtarget = size-1;
        int i=0;
        
        while(i < Orgtarget)
        {
            if(nums[i] >= target)
                return true;
            if(nums[i]== 0)
                return false;
            i = calNextPos(nums,i);
            target = Orgtarget - i; 
        }
        return true;
    }
    
    int calNextPos(vector<int>& nums,int pos)
    {
        int jumps = nums[pos];
        int range = pos;
        int finalPos = pos;
        
        for(int i=1;i<=jumps;i++)
        {
            int tempRange = nums[pos+i]+pos+i;
            if(tempRange>range)
            {
                range = tempRange;
                finalPos = pos+i;
            }
        }
        return finalPos;
    }
};
