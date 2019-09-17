/*You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.*/


int coinChange(vector<int>& denom, int change) 
    {
        int size = denom.size();
        if(change ==0)
            return 0;
        vector<int> coinArray(change+1,INT_MAX);
        coinArray[0] = 0;
        
        //For every number
        for(int i=1;i<= change;i++)
        {
            int min = INT_MAX;
            
            //Checking every coin
            for(int j=0;j<size;j++)
            {
                if(i - denom[j] >=0)
                {
                    int coinsReq = coinArray[(i-denom[j])];
                    if(coinsReq != INT_MAX)
                        coinsReq++;
                    if(min > coinsReq)
                    {min = coinsReq;}
                }
            }
            
            coinArray[i] = min;
        }
        
        if(coinArray[change] == INT_MAX)
            return -1;
        
        return coinArray[change];
    }
