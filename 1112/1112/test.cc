//#define _CRT_SECURE_NO_WARNINGS 1
//
////#include <iostream>
////using namespace std;
////#include<string>
////
////int main()
////{
////    string s;
////    cin >> s;
////    string ret;
////    for (auto i : s)
////    {
////        if (s[i + 1] == '\n')
////            break;
////        if (s[i + 1] == ' ')
////            ret += s[i];
////    }
////    cout << ret << endl;
////    return 0;
////}
//
////#include <cctype>
////#include <iostream>
////using namespace std;
////#include<string>
////
////int main() {
////    string s;
////    // cin >> s;
////    getline(cin, s);
////    string ret;
////    // for(auto i : s)
////    // {
////    //     if(s[i+1] == '\n')
////    //         break;
////    //     if(s[i+1] == ' ')
////    //         ret += s[i];
////    // }
////
////    for (int i = 0; i < s.length() - 1; i++)
////    {
////        if (s[i + 1] == ' ')
////            ret += s[i];
////    }
////
////    for (auto& i : ret)
////    {
////        cout << (char)toupper(i);
////    }
////
////    cout << endl;
////    return 0;
////}
//
//#include <iostream>
//using namespace std;
//
////int main()
////{
////    int n, x;
////    cin >> n >> x;
////    int l = 0, r = 0;
////    int prevl, prevr;
////    int a[n];
////    for (int i = 0; i < n; i++)
////    {
////        int num;
////        cin >> num;
////        a[i] = num;
////    }
////
////    int sum = 0;
////    int ret = 0x3f3f3f3f;
////    for (int i = 0; i < n; i++)
////    {
////        if (sum < x)
////        {
////            sum += a[r++];
////        }
////        else
////        {
////            sum -= a[l++];
////        }
////    }
////}
//
//#include <cstdlib>
//#include <iostream>
//using namespace std;
//#include <stdlib.h>
//
//int compare_int(const void* a, const void* b) {
//    // 将 void* 转换为 int*，再解引用获取值
//    int val1 = *(const int*)a;
//    int val2 = *(const int*)b;
//    return val1 - val2;  // 升序（val1 < val2 时返回负）
//}
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//
//    int num[n];
//
//    for (int i = 0; i < n; i++)
//        cin >> num[i];
//
//    // 对数组进行排序
//
//    // 找数组中最大的偶数，进行除操作
//    qsort(num, sizeof(num) / sizeof(num[0]), sizeof(num[0]), compare_int);
//    for (int i = 0; i < k; i++) {
//        for (int j = n - 1; j > 0; j--) {
//            if (num[j] % 2 == 0) {
//                num[j] /= 2;
//                qsort(num, sizeof(num) / sizeof(num[0]), sizeof(num[0]), compare_int);
//                break;
//            }
//        }
//    }
//
//    int sum = 0;
//    for (auto i : num) {
//        sum += i;
//    }
//    cout << sum << endl;
//
//    return 0;
//}

// https://www.nowcoder.com/practice/0cfa856bf0d649b88f6260d878f35bb4?tpId=290&tqId=39937&ru=/exam/oj
//#include <iostream>
//using namespace std;
//#include <string>
//int main() {
//    string s;
//    while (cin >> s) {
//        if (s[0] <= 'z' && s[0] >= 'a') cout << (char)(s[0] - 32);
//        else cout << s[0];
//    }
//    return 0;
//}

// https://ac.nowcoder.com/acm/problem/221681
//#include<iostream>
//
//using namespace std;
//
//int N = 1e7 + 10;
//
//int arr[N];
//
//int n, x; // 封装全局的意义：可以避免函数传参
//
//int main()
//{
//    cin >> n >> x;
//    for (int i = 1; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//
//    int retlen = N, retleft = -1, retright = -1, sum;
//    int left = 0, right = 0;
//    while (right <= n)
//    {
//        sum += arr[right];
//        while (sum >= x)
//        {
//            if (right - left + 1 < retlen)
//            {
//                retleft = left;
//                retright = right;
//                retlen = right - left + 1;
//            }
//            sum -= arr[left++];
//        }
//        right++;
//    }
//    cout << retleft << " " << retright << endl;
//
//    return 0;
//}

// https://ac.nowcoder.com/acm/problem/213140

#include<iostream>
#include<queue>

using namespace std;
typedef long long LL;

LL n, k;
priority_queue<LL> heap;

int main()
{
    cin >> n >> k;
    LL sum = 0, x;

    while (n--)
    {
        cin >> x;
        sum += x;
        if (x % 2 == 0)
            heap.push(x);
    }

    while (heap.size() && k--)
    {
        LL t = heap.top() / 2;
        heap.pop();
        sum -= t;
        if (t % 2 == 0) heap.push(t);
    }
    cout << sum << endl;
    return 0;
}