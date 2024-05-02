// We define a class Solution which contains a function findMaxK that takes a reference to a vector of integers (vector<int>& nums) as input.
// Inside the function, we use an unordered set (unordered_set<int> set) to store unique elements from the input vector. This ensures that each element is considered only once.
// We initialize the answer variable (int ans) to -1, which will be updated with the maximum K value found.
// We iterate through the input vector and insert each element into the unordered set to eliminate duplicates.
// Next, we sort the input vector in non-increasing order using sort function with greater<int>() comparator. This makes it easier to compare elements with their negatives.
// We then iterate through the sorted vector to find the maximum K value. For each element x, we check if its negative exists in the set. If it does, we update the answer variable and exit the loop.
// Finally, we return the maximum K value found.


class Solution {
public:
    int findMaxK(vector<int>& nums) {
         unordered_set<int> set;
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        for (auto x : nums) {
            if (set.find(-x) != set.end()) {
                ans = x;
                break; // Exit loop once we find the max K value
            }
        }
        return ans;
    }
};
