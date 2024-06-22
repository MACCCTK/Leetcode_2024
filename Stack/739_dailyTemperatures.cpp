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
