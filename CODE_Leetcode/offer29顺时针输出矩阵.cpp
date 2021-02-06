/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
};

// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
// 这里 x width 象征的是垂直的坐标系 y height象征的是水平的坐标系和移动，我写反了。
// 基本的分析如图。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        // 初始参数设置
        bool ishori = false; // 先执行水平的 height才是水平
        int offset_x=0,offset_y=0,xi=0,yi=-1;
        int width=matrix.size(), height=matrix[0].size();

        // 水平和垂直写反了，
        while(width-offset_x && height-offset_y){
            int step = 0;
            if(ishori){
                while(step<width-offset_x){
                    xi = offset_x%2!=0? xi+1: xi-1;  // 基于就奇偶判断给xi上偏移量
                    res.push_back(matrix[xi][yi]);
                    step++;
                }
                ishori = false; offset_y++;
                // 基于就奇偶判断给yi上偏移量
                // yi = offset_x%2==0? yi+1:yi-1;
            }else{
                while(step<height-offset_y){
                    yi = offset_y%2==0? yi+1: yi-1; // 基于就奇偶判断给yi上偏移量
                    res.push_back(matrix[xi][yi]);
                    step++;
                }
                ishori = true; offset_x++;
                // xi = offset_y%2!=0? xi-1:xi+1;
                // 基于就奇偶判断给xi上偏移量
            }
        }
        return res;
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}