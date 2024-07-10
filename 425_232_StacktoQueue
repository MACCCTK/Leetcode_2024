//
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        int res = this->pop(); // 在 C++ 中，this 指针是一个特殊的指针，它指向当前对象的实例（地址）。
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};
