#define _CRT_SECURE_NO_WARNINGS 1

// https://www.nowcoder.com/practice/41b42e7b3c3547e3acf8e90c41d98270?tpId=290&tqId=39852&ru=/exam/oj
//#include <cstddef>
//#include<iostream>
//#include <locale>
//#include <regex>
//using namespace std;
//
//int main() {
//    float weight;
//    char ch;
//    cin >> weight >> ch;
//
//    size_t money = 0;
//    // 先判断是否加急
//    if (ch == 'y')
//        money += 5;
//    // 判断重量
//    if (weight <= 1)
//        money += 20;
//    else
//    {
//        money += 20;
//        money += (int)weight;
//    }
//    cout << money;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//#include<cmath>
//
//int main() {
//    float w;
//    char ch;
//    int ret = 0;
//
//    cin >> w >> ch;
//
//    if (w <= 1)
//        ret += 20;
//    else {
//        ret += 20;
//        w -= 1;
//        ret += ceil(w);
//    }
//
//    if (ch == 'y')
//        ret += 5;
//
//    cout << ret << endl;
//
//    return 0;
//}


// https://www.nowcoder.com/practice/9b969a3ec20149e3b870b256ad40844e?tpId=230&tqId=39751&ru=/exam/oj
//#include<iostream>
//#include<cstring>
//
///*
//描述
//给定一个整数数组 cost  ，其中 cost[i] 是从楼梯第i 个台阶向上爬需要支付的费用，下标从0开始。
//一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//*/
//using namespace std;
//const int MAXN = 100000 + 1;
//int cost[MAXN];
//int dp[MAXN];
//
////手写分析过程：
////从大到小分析 对于第 i 阶，到顶需要的花费   dp[i] = cost[i] + min(dp[i + 1] , dp[i + 2])
////最后取 min(dp[0] , dp[1])
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> cost[i];
//    }
//    if (n == 1) {
//        cout << cost[0] << endl;
//        return 0;
//    }
//    else if (n == 2) {
//        cout << min(cost[0], cost[1]);
//        return 0;
//    }
//    else {
//        memset(dp, 0, sizeof(dp));
//        //dp初始化 对于最后一阶和倒数第二阶而言，他们需要的花费就是他们位置的cost
//        dp[n - 1] = cost[n - 1];
//        dp[n - 2] = cost[n - 2];
//        //从单数第三个开始，花费 就是 cost[i] + min(dp[i + 1] , dp[i + 2])
//        //跳一步 和 跳两步 两种情况取花费少的情况
//        for (int i = n - 3; i >= 0; --i) {
//            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
//        }
//        //最后从“从0开始”和“从1开始” 两者选小的那个
//        //实际上，二者表达的是 从0 、1开始之后的能实现的最低花费已经计算出来了
//        //选择只是为了选择 “从哪个开始更优”
//        cout << min(dp[0], dp[1]) << endl;
//    }
//
//    return 0;
//}

// https://www.nowcoder.com/questionTerminal/2c6a0a8e1d20492f92941400036e0890
#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string s;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    int prev1 = -1, prev2 = -1, ret = 0x3f3f3f3f;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == s1) {
            if (prev2 != -1)
                ret = min(ret, i - prev2);
            prev1 = i;
        }
        if (s == s2) {
            if (prev1 != -1)
                ret = min(ret, i - prev1);
            prev2 = i;
        }
    }
    if (ret == 0x3f3f3f3f) cout << -1 << endl;
    else cout << ret << endl;

    return 0;
}



