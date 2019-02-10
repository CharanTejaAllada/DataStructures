//Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
//Find two lines, which together with x-axis forms a container, such that the container contains the most water.


class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max_area = 0;
        int size = height.size();
        if(size < 2)
            return 0;
        
        for(int i=0;i<size-1;i++)
        {
            for(int j= i+1; j<size; j++)
            {
                int area_now = findArea(i,j,height[i],height[j]);
                if(max_area < area_now)
                    max_area = area_now;
            }
        }
        
        return max_area;
    }
    
    int findArea(int i,int j, int ivalue, int jvalue)
    {
        int length;
        length = (ivalue < jvalue) ? ivalue : jvalue;
        
        return length*(j-i);
    }
};
