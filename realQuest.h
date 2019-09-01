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
    // 输出最大值 偶数优先级 > 奇数 同等级更大的大
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