public:
//如果是快乐数 那么最终会变成1  
//如果不是快乐数 那么必然存在一个循环 
//可不可能数字都是杂乱无章的呢? 也就是没有循环 也不变成1
// 9->81  99->162  999->243  9999->324 99999->405  且如果x<9...9  那么处理后的数字小于 9...9处理的数字  eg:82->68
//所以一个很大的数 处理之后位数变小 逐渐从x位->..->4位->3位  比如9999/99999他们变成3位 这3位<=999 然后变换<=243 当然也可能<=162甚至<=81
//但最终数字一定会<=243 而这里面的数是有限的 
//最多就243个位置 所以不可能杂乱无章 两种可能1.要么有循环 才可以无限下去  2.要么变到1

//做法1：哈希集 2.循环可以看成是环 判断有无环：快慢指针
class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
          int slow = n;
          int fast = n;
          while (true) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
            if(fast == 1 || slow == 1)
             return true;
            if(fast == slow)
             return false;
          }
    }
};
