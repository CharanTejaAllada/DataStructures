/* Leetcode hard
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

class Solution {
public:
    
    vector<int> sortedList;
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        int size = nums.size();
        
        vector<int> count_list;
        
        for(int i= size - 1; i>=0 ; i--)
        {
            count_list.insert(count_list.begin(),getCount(nums[i]));
        }
        
        return count_list;
    }
    
    int getCount(int num)
    {
        if(sortedList.size()==0)
        {
            sortedList.push_back(num);
            return 0;
        }
        
        else
        {
            for(int i=0;i<sortedList.size();i++)
            {
                if(sortedList[i]>=num)
                {
                    sortedList.insert(sortedList.begin()+i,num);
                    return i;
                }
            }
        }
        
        sortedList.push_back(num);
        
        return (sortedList.size()-1);
    }
};

// Approach:
//Imagine the given numbers as height of kids standing a line and here each kid is trying to figure out how
//many kids infront are shorter than him.
//Now in real world, if you take a kids line which is unsorted like this and you started to sort it.
//The sorting starts with very first kid in the line. In our case the first kid is the last element of vector 
//because we are trying to determine the heights shorter towards right.
//Now it is your turn to get into the sorted line because all the other kids infront of you are in sorted line.
//Now you are getting pushed into the sorted line.... the position of you in the sorted line is same as the 
//number of kids shorter infront of you. 
//Right? because the sorted line has only people infront of you(in our case, towards right). 
//Likewise we determine the number of shorter kids number for every kid.
