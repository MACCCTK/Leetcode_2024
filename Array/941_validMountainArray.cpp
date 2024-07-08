class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int left = 0;
        int right = A.size() - 1;

        while (left < A.size() - 1 && A[left] < A[left + 1]) left++;
        while (right > 0 && A[right] < A[right - 1]) right--;
        if (left == right && left != 0 && right != A.size() - 1) return true;
        return false;
    }
};
