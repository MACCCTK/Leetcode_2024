//给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//2024_0808 第一次回顾

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> result(T.size(), 0);
        st.push(0);
        for (int i = 1; i < T.size(); i++) {
            if (T[i] < T[st.top()]) {                       // 小于入栈
                st.push(i);
            } else if (T[i] == T[st.top()]) {               // 等于入栈
                st.push(i);
            } else {
                while (!st.empty() && T[i] > T[st.top()]) { // 大于出栈
                    result[st.top()] = i - st.top();//隔几天
                    st.pop();
                }
                st.push(i);//新元素入栈
            }
        }
        return result;
    }
};

//时间复杂度：O(n)，其中 n 是温度列表的长度。正向遍历温度列表一遍，对于温度列表中的每个下标，最多有一次进栈和出栈的操作。
//空间复杂度：O(n)，其中 n 是温度列表的长度。需要维护一个单调栈存储温度列表中的下标。


//简化版本：
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!st.empty() && T[i] > T[st.top()]) { // 注意栈不能为空
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);

        }
        return result;
    }
};
