/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        if(piles.empty()) return 0;
        // 然后我们发现这个遍历问题这种搜索过程实际上可以用二分法来解决
        int right = getmax(piles)+1;
        int left = 1;
        while(left<right){
            int mid = (left + right)>>1;
            if(dayNeed(piles,mid)<=H){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
        
    }
    int dayNeed(vector<int> piles, int K){
        // 首先需要一个判断多久能吃完的子函数
        
        int n = piles.size();
        int index = 0, res = 0;
        for(auto nums:piles) 
          res += (nums-1)/K +1;
        // cout<<K<<" "<<res<<endl;
        return res;
    }
    int getmax(vector<int>& piles){
        // 找到堆中的最大值
        int maxvalue = 0;
        for(auto num: piles){
            if (num>maxvalue)
                maxvalue = num;
        }
        
        return maxvalue;
    }
};
// 官方的题解下面的写的比我写的好得多，然后为什么num需要-1再÷？
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = pow(10, 9);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!possible(piles, H, mi))
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    // Can Koko eat all bananas in H hours with eating speed K?
    bool possible(vector<int>& piles, int H, int K) {
        int time = 0;
        for (int p: piles)
            time += (p - 1) / K + 1;
        return time <= H;
    }
};

作者：LeetCode
链接：https://leetcode-cn.com/problems/koko-eating-bananas/solution/ai-chi-xiang-jiao-de-ke-ke-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

