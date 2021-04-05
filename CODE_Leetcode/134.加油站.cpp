/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        // count how long we can reach by this 
        int count;
        // record now we have 
        int curr = 0;
        for(int i = 0; i < n; i++){
            count = 0; curr = 0;
            while(count<n){
                int j = i + count;
                curr = curr + gas[j%n] - cost[j%n];
                if( curr>=0){
                    count++; 
                }
                else {
                    // 这里有个小技巧，就是我们可以从第一个我们无法到达的站点开始继续计算
                    // 因为我们从无法到达的中间某个节点出发，必然都到不了
                    i += count;
                    break;
                }
                    
            }
            if(count == n){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

