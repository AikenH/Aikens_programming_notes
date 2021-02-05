/*leetcode中算法的测试样板
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>

using namespace std;
// -----------------------------------------question--------------------------

// -----------------------------------------ans--------------------------------
class Solution {
public:
    bool isNumber(string s) {
        // 实际上要考虑的特殊value只有 + - E e .
        // 经过 + - E的以后，还是能接受一样的类型，但是没办法进行同样的符号判断了，就是不能重复出现
        // FIXME：可以使用递进的方法，也就是将前面的数字一个个吞掉，这样就不用考虑到重复判断的问题了，只需要进行函数的调用
        // 但是经过.后，就什么符号都不能出现了，只能是纯整数。
        if(s.empty()) return false;
        int index = 0;
        bool cures;
        // 前面是' '的情况
        while(index<s.size()){
            if(s[index]==' ') index++;
            else break;
        }
        cures = isInteger(s,index);
        if(s[index] == '.')
        {
            // 以.开头的到底算不算呢？
            // 那以.结尾的呢？
            // .e 也算，那我tmd 不是白写了，我觉得这题有病。
            index++;
            if (index != s.size()){
                //".  "的情况
                if(s[index] == ' '){
                    while(index<s.size()){
                        if(s[index]==' ') index++;
                        else return false;
                    }
                }
                // .e（的情况）
                else if(s[index] == 'e' || s[index]== 'E')
                    cures = cures && isInteger(s,++index);
                // '.的普通情况'
                else
                    cures = isUnsignedInteger(s,index);
            }
            // ’.直接结束的情况‘
            else
                return cures; 
        }
        if(s[index] == 'e' || s[index] == 'E')
        {
            index ++;
            cures = cures && isInteger(s, index);
        }
        // 遍历完了才算完事儿
        // 后面是’ ‘的
        while(index<s.size()){
            if(s[index]==' ') index++;
            else break;
        }
        return cures && index == s.size();

    }
    bool isUnsignedInteger(string& s, int& index){
        // 判断是不是纯整数，用于.后的情况
        // 通过数值的ascii码，转化为数字的大小来进行比较,而且\0不会包含在string的size里面
        int begin = index;
        for (;index<s.size();index++){
            if(s[index]>='0' && s[index]<='9'){}
            else break; // 这里直接return好不好呢，因为后续的话还要加入额外的判断。
        }
        return index>begin;
    }
    bool isInteger(string& s, int& index){
        // 考虑包含 + - 符号
        if (s[index] == '+' || s[index] == '-') index++;
        return isUnsignedInteger(s,index);
    }
};
// -----------------------------------------test--------------------------------
// 在这个地方编写测试样例并进行测试；
int main()
{
    std::cin.get();
}

/*
1. 为什么他们没考虑HOI的组合爆炸问题；
2. 米勒心理学的约束；
3. 从理论基础上，心理学，数学，集合，我们的方法为啥好，别人和自己的方法的优点是啥；
   理论支撑基础不足，传统方法到底弱在哪，从科学和理论的问题来说。从量化的标准批判他不可行；
4. 人类行为学研究；
5. 为什么我们特征压缩以后。
6. 不局限在教师场景，应该放在MPMO的场景里。
*/