/*
考虑相邻差的累积和，如果累积和小于0，则max清零。否则只要是正的就一直累加。
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int finalmax = 0;
        if (prices.size() <= 1) return 0;
        for (int i = 1; i<prices.size(); i++){
            max += prices[i] - prices[i-1];
            if (max < 0)
                 max = 0;
            
            
            if (max > finalmax) 
                finalmax = max;
        }
        
        /* Time limit
        for (int i = 1; i<prices.size(); i++){
            for(int j = i-1; j>=0; j--){
                if(prices[i] - prices[j] > max){
                    max = prices[i] - prices[j];
                } 
            }   
        }
        */
        return finalmax;
    }
};