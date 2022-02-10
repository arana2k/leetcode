// DAY 7(389. Find the Difference)=============================================================================================


int findPairs(vector<int> &nums, int k) {
        map<int, int> hash;
        int pairs = 0, len = nums.size(), sum;
        for (auto &n: nums) {
            ++hash[n];
        }

        for (int i = 0; i < len; ++i) {
            sum = (nums[i] + k);
            if (hash[sum] > 0) {
                if (sum == nums[i]) {
                    pairs = (hash[sum] > 1) ? pairs + 1 : pairs;
                } else {
                    ++pairs;
                }
                hash[sum] = 0;
            }
        }

        return pairs;
    }
