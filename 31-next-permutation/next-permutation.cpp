class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int piv = -1;

        // Step 1: Find the pivot
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                piv = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse the entire array
        if (piv == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find the next greater element from the end
        for (int i = n - 1; i > piv; i--) {
            if (A[i] > A[piv]) {
                swap(A[i], A[piv]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(A.begin() + piv + 1, A.end());
    }
};