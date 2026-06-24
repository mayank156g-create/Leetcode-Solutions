class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {

        int lcp = 0;

        int n = min({s1.size(), s2.size(), s3.size()});

        while (lcp < n &&
               s1[lcp] == s2[lcp] &&
               s2[lcp] == s3[lcp]) {
            lcp++;
        }

        if (lcp == 0)
            return -1;

        return (s1.size() - lcp) +
               (s2.size() - lcp) +
               (s3.size() - lcp);
    }
};