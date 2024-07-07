class Solution {
private:
string getString(const string& S) {
    string s;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != '#') s += S[i];
        else if (!s.empty()) {
            s.pop_back();
        }
    }
    return s;
}
public:
    bool backspaceCompare(string S, string T) {
        return getString(S) == getString(T);
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sSkipNum = 0; // 记录S的#数量
        int tSkipNum = 0; // 记录T的#数量
        int i = S.size() - 1;
        int j = T.size() - 1;
        while (1) {
            while (i >= 0) { // 从后向前，消除S的#
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) { // 从后向前，消除T的#
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
          //开始比较存在的字母
            if (i < 0 || j < 0) break;
            if (S[i] != T[j]) return false;
            i--;j--;
        }
        if (i == -1 && j == -1) return true;
        return false;
    }
};
