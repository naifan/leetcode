/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

我的思路：三个一下的数据直接出结果。三个以上的时候：波峰卖，波谷买。
每次找波峰，再在波峰与上一个波峰前找最小的买。
难点在于：边界处理。后来先找出第一个波峰，和第二个波峰，然后分情况分情况处理。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {   //低买高卖，波谷买，波峰卖。
        int firstpeak = 0;
        int finalpeak = 0;
        int lastpeak, peak, low;
        int max = 0;
        
        if (prices.empty()) return 0;
        if (prices.size() == 1) {
            return 0;
        }
        if (prices.size() == 2 ){
            if (prices[0] >= prices[1]){
                return 0;
            }
            else {
                max = prices[1] - prices[0];
                return max;
            }
        }
        else {
            //find firstpeak
            firstpeak = prices.size()-1;
            for(int i=1; i < prices.size(); i++){
                //firstpeak = prices.size()-1;
                if (prices[i-1] > prices[i]){  //第一个peak；
                    firstpeak = i-1;
                    break;
                }
            }  // end for find fistpeak
            
            //find finalpeak
            finalpeak = 0;
            for (int i=prices.size()-1; i>=0; i--){
                //finalpeak = 0;
                if (prices[i-1] <= prices[i]){
                    finalpeak = i;
                    break;
                }
            }
            
                

            max += prices[firstpeak] - prices[0];  //firstpeak == 0 时加0
            lastpeak = firstpeak;
            
            for (int i = lastpeak+1; i < finalpeak; i++){
                if ((prices[i] > prices[i+1]) && ( prices[i] >= prices[i-1])) { //peak
                    peak = i;
                    low = lastpeak +1;
                    for (int j = lastpeak+1; j < peak; j++ ){
                        //low = j;
                        if (prices[j] < prices[low]) low = j;
                    }
                    max += prices[peak] - prices[low];
                    lastpeak = peak;
                } 
            }  
            
            if( lastpeak != finalpeak){
                low = lastpeak +1;
                for (int j = lastpeak+1; j < finalpeak; j++){
                    //low = j;
                    if (prices[j] < prices[low]) 
                        low = j;
                }
                max += prices[finalpeak] - prices[low];
            }
            
            return max;
        
    } //else size > 3
    }
};
