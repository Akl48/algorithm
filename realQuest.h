#include "config.h"

class PDD {
    // 自定义优先级比较器
struct comp {
    bool operator () (const int num1,const int num2) {
        int res1 = num1 % 2,res2 = num2 % 2;
        if (res1 == res2){
            return (num1 < num2);
        } else {
            return res1 ? true : false;
        }
        return false;
    }
};
    // 给定一个以,号区分的字符串后面跟着一个以;的数字 输出最大值 偶数优先级 > 奇数 同等级更大的大
void printMax(string &str){
    int len = (int)str.length() - 1;
    int i = 0;
    priority_queue<int,vector<int>,comp> queue;
    int k = 0;
    while (i <= len) {
        int start = i;
        int j = 0;
        for (j = i ; j < len ; j++ ) {
            if (str[j] == ','||str[j] == ';') {
                string newStr = str.substr(start,j - start); // 截取string中的数字
                int val = atoi(newStr.c_str()); // 转换为数字
                queue.push(val); // 加入优先级队列
                if(str[j] == ';') { // 若为分号 加载完之后直接退出k = j+1;
                    string newC = str.substr(j+1,len - j);
                    k = atoi(newC.c_str());
                }
                break;
            }
        }
        if (k) break; // 若k不为0 则已经读区完毕
        i = j + 1;
    }
    while (k) {
        cout<<queue.top();
        queue.pop();
        k--;
        if (k) {
            cout<<',';
        }
    }
    return ;
}
};

class ByteDance {
    /*
    给定一个数组完成对数组的乱序（洗牌算法）
    */
    void mergeCard(vector<int> &array) {
        int len = (int)array.size();
        if (len <= 1) return;
        vector<int> newArray;
        for (int i = len - 1; i >= 0 ; i++ ) {
            srand(unsigned(time(NULL)));
            int index = rand() % i;
            newArray.push_back(array[index]);
            array.erase(array.begin()+index);
        }
    }
};

class sina {
    /*
        约瑟夫环问题数学
    */
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0) return -1;
        if (n == 1) return 0;
        return (LastRemaining_Solution(n - 1 , m) + m) % n;
    }
    /*
        字符串变换问题dp
    */
};