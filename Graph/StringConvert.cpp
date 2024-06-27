#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
int main() {
    string beginStr, endStr, str;
    int n;
    cin >> n;
    unordered_set<string> strSet;
    cin >> beginStr >> endStr;
    for (int i = 0; i < n; i++) {
        cin >> str;
        strSet.insert(str);//使用set来检查字符串是否出现在字符串集合里更快一些
    }
  
    unordered_map<string, int> visitMap; // <记录的字符串，路径长度>
    queue<string> que;
    que.push(beginStr);
    visitMap.insert(pair<string, int>(beginStr, 1));

    while(!que.empty()) {
        string word = que.front();
        que.pop();
        int path = visitMap[word]; // 这个字符串在路径中的长度

        for (int i = 0; i < word.size(); i++) {
            string newWord = word;
            for (int j = 0 ; j < 26; j++) {
                newWord[i] = j + 'a';
                if (newWord == endStr) { 
                    cout <<  path + 1 << endl; // 找到了路径 
                    return 0;
                }
                // 字符串集合里出现了newWord，并且newWord没有被访问过
                if (strSet.find(newWord) != strSet.end()
                        && visitMap.find(newWord) == visitMap.end()) {
                    visitMap.insert(pair<string, int>(newWord, path + 1));
                    que.push(newWord);//广度优先（先访问完一层树）
                }
            }
        }
    }
    cout << 0 << endl;

}
