// DAY 1 (121. Best Time to Buy and Sell Stock)================================================================================

int maxProfit(vector<int> &prices)
{
    int mn = INT_MAX, ans = 0;
    for (int x : prices)
    {
        ans = max(ans, x - mn);
        mn = min(mn, x);
    }
    return ans;
}

// DAY 2 (438. Find All Anagrams in a String)======================================================================

vector<int> findAnagrams(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<int> ans;
    if (n < m)
        return ans;

    vector<int> sx(26, 0), px(26, 0);
    for (int i = 0; i < m; i++)
        sx[s[i] - 'a']++;
    for (int i = 0; i < m; i++)
        px[p[i] - 'a']++;

    if (sx == px)
        ans.push_back(0);

    for (int i = m; i < n; i++)
    {
        sx[s[i] - 'a']++;
        sx[s[i - m] - 'a']--;
        if (sx == px)
            ans.push_back(i - m + 1);
    }

    return ans;
}

// DAY 3 (454. 4Sum II)=========================================================================================

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int n = nums1.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mp[nums1[i] + nums2[j]]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += mp[-(nums3[i] + nums4[j])];

    return ans;
}

// DAY 4 (525. Contiguous Array)======================================================================

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> mp;
    mp[0] = -1;
    int pol = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pol += (nums[i] == 1);
        pol -= (nums[i] == 0);
        if (!mp.count(pol))
            mp[pol] = i;
        else
            ans = max(ans, i - mp[pol]);
    }
    return ans;
}

// DAY 5 (23. Merge k Sorted Lists)=============================================================================

// APPROACH 1 (Using Priority Queue) --> O(n*log(k))

struct comp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    for (int i = 0; i < lists.size(); i++)
        if (lists[i])
            pq.push(lists[i]);

    ListNode *ans = new ListNode(INT_MIN), *itr = ans;
    while (!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();
        ListNode *nxt = node->next;
        if (nxt)
            pq.push(nxt);

        itr->next = node;
        itr = itr->next;
    }

    return ans->next;
}

// APPROACH 2 (DIVIDE)

// METHOD 1 (Brute Force) --> O(n*k) [n -> total nodes]

ListNode *merge2lists(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(INT_MIN), *itr = ans;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            itr->next = l1;
            l1 = l1->next;
        }
        else
        {
            itr->next = l2;
            l2 = l2->next;
        }
        itr = itr->next;
    }
    itr->next = l1 ? l1 : l2;
    return ans->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    ListNode *ans = new ListNode(INT_MIN);
    for (int i = 0; i < lists.size(); i++)
        ans = merge2lists(ans, lists[i]);

    return ans->next;
}

// METHOD 2 (Divide and Conquer) --> O(n*logn(k)) [n -> total nodes] [O(1) space]

ListNode *merge2lists(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(INT_MIN), *itr = ans;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            itr->next = l1;
            l1 = l1->next;
        }
        else
        {
            itr->next = l2;
            l2 = l2->next;
        }
        itr = itr->next;
    }
    itr->next = l1 ? l1 : l2;
    return ans->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    for (int i = 1; i < lists.size(); i *= 2)
        for (int j = 0; i + j < lists.size(); j += (i * 2))
            lists[j] = merge2lists(lists[j], lists[i + j]);

    return lists[0];
}

// DAY 6 (80. Remove Duplicates from Sorted Array II)===========================================================================

int removeDuplicates(vector<int> &nums)
{
    unordered_map<int, int> m;
    int i = 0, j = 0;
    while (i < nums.size())
    {
        if (++m[nums[i]] <= 2)
            swap(nums[i], nums[j++]);
        i++;
    }
    return j;
}

// DAY 7(389. Find the Difference)=============================================================================================

//METHOD(BITWISE OPERATION (USE OF XOR))

char findTheDifference(string s, string t) {
        char c = 0;
        for(char cs: s) c ^= cs;
        for(char ct: t) c ^= ct;
        return c;
    }
};

// DAY 8(258. Add Digits)=============================================================================================

//RECURSION :


class Solution {
public:
    int addDigits(int num) {
      int sum=0;
        while(num)
        {
            sum+=(num%10);
            num/=10;
        }
        if(sum<10)
            return sum;
        else
            return addDigits(sum);
    }
};

//ITERATION :


class Solution {
public:
    int addDigits(int num) {
      int sum=0;
        while(num>9)
        {
            while(num)
            {
                sum+=(num%10);
                num/=10;
            }
            num=sum;
            sum=0;
        }
        return num;
    }
};

// DAY 9(532. K-diff Pairs in an Array)=============================================================================================

//we have to find all pairs the array which have an absolute difference of 'k' and then eliminate those which are not unique.


//Using maps

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;
        int ans=0;
        for(auto x:a)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(a.find(x.first+k)!=a.end())
                ans++;
        }
        
        return ans;
    }
};

//using two pointer

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,i=0,j=1;
        for(i,j;i<nums.size() and j<nums.size();)
        {
            if(i==j or nums[j]-nums[i]<k)
                j++;
            else 
            {
                if(nums[j]-nums[i]==k)
                {
                    ans++;
                    j++;
                    for(;j<nums.size();j++)
                        if(nums[j]!=nums[j-1])
                            break;
                    if(j==nums.size())
                    return ans;
                    j--;                  
                }
                i++;
                while(i<j and nums[i]==nums[i-1])
                    i++;
            }
        }
        return ans;
    }
};

// DAY 10(560. Subarray Sum Equals K)=============================================================================================

/*
we keep an accumulator variable sum with the running total of the sum of numbers; we then check if we have already met that values using our seen hashmap that acts more or less like a frequency table, storing how many times we have encountered a specific value: sum - k.
That is why if have met sum - k before and now the value is sum, the difference between those specific points and the current iteration is, by definiton, exactly k: we are now at sum, so, the interval between the previous point(s) and now sums up to, by definition, sum - (sum - k), which equates k.
We collect all those occurrences in count and finally we return it.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> seen = {{0, 1}};
        int count = 0, sum = 0;
        for (auto n: nums) {
            sum += n;
            count += seen[sum - k];
            seen[sum]++;
        }
        return count;
    }
};

// DAY 11(567. Permutation in String)=============================================================================================

/*
Basic Idea :

The alphabets in a permutation that is to be searched will always be the same, and so will their count.
The thing that counts in s2 is that each substring has the same number of characters as in s1. As a result, 
we make a hashmap that contains the count of each character in the string s1. After that, we slide a window over 
the string s2 and lower the number for characters that appear in the window. When all of the counters in the hashmap 
reach 0, we've found the permutation.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map< char, int >mp;    //Use hashmap to store the frequencies of all the characters present in string s1.
        for(auto it : s1){
            mp[it]++;
        }
        int count = mp.size();         //Use the count variable to see if all of the characters in the map have the same frequency, indicating that an anagram has been found.
        int i = 0, j = 0;
        int k = s1.size();             //Window Size
        while(j < s2.size()){
            if(mp.find(s2[j]) != mp.end()){      //If a character is found that already exists in the map, reduce its frequency by one.
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){     //If the frequency of a specific character on the map is 0, it means that all occurrences of that character is found inside the current window size.
                    count--;
                }
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
				if(count == 0){    //Anagram found 
					return true;  
				}
                if(mp.find(s2[i]) != mp.end()){  //Check if that character is present in the map while sliding the window, then increase its frequency by one, as we decreased its frequency when we first met it while crossing the window.
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return false;
    }
};

// DAY 12(127. Word Ladder)=============================================================================================




class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};


// DAY 13(78. Subsets)=============================================================================================

//Recursive (Backtracking)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};


//Iterative


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};


//Bit Manipulation

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};

// DAY 14(104. Maximum Depth of Binary Tree)=============================================================================================


//Depth-first-search

int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight)+1;
    }



//Breadth-first-search
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }
    
    return res;
}

// DAY 15(136. Single Number)=============================================================================================

//USING MAPS (NOT USING CONSTANT SPACE )

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
}


//USING SORTING (USING CONSTANT SPACE )

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
}

//using xor method

class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};


// DAY 16(24. Swap Nodes in Pairs)=============================================================================================


  ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // 2 is new head, 1 is head
        ListNode* new_head = head->next;
        // store 3
        ListNode* third = head->next->next;
        // 2->1
        new_head->next = head;
        // 1->3
        head->next = swapPairs(third);
        
        return new_head;
    }


// DAY 17(39. Combination Sum)=============================================================================================

//explanination
/*

1. Sort the vector(non-decreasing).
2. First remove all the duplicates from vector.
3. Then use recursion and backtracking to solve 
   the problem.
   (A) If at any time sub-problem sum == 0 then 
       add that vector to the result (vector of 
       vectors).
   (B) Else if sum is negative then ignore that 
       sub-problem.
   (C) Else insert the present index in that 
       vector to the current vector and call 
       the function with sum = sum-ar[index] and
       index = index, then pop that element from 
       current index (backtrack) and call the 
       function with sum = sum and index = index+1
       
       */

class Solution {
public:

    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i)
    {
        
        if(target == 0)
        {
            // if we get exact answer
            res.push_back(r);
            return;
        }
        
        while(i <  candidates.size() && target - candidates[i] >= 0)
        {
            // Till every element in the array starting
            // from i which can contribute to the target
            r.push_back(candidates[i]);// add them to vector
            
            // recur for next numbers
            Sum(candidates,target - candidates[i],res,r,i);
            ++i;
            
            // Remove number from vector (backtracking)
            r.pop_back();
        }
}
    
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); // sort candidates array
        
        // remove duplicates
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
        vector<int> r;
        vector<vector<int> > res;
        
        Sum(candidates,target,res,r,0);
        
        return res;
    }
};

// DAY 18(402. Remove K Digits)=============================================================================================

class Solution {
public:
    string removeKdigits(string num, int k) {
        // number of operation greater than length we return an empty string
        if(num.length() <= k)   
            return "0";
        
        // k is 0 , no need of removing /  preforming any operation
        if(k == 0)
            return num;
        
        string res = "";// result string
        stack <char> s; // char stack
        
        s.push(num[0]); // pushing first character into stack
        
        for(int i = 1; i<num.length(); ++i)
        {
            while(k > 0 && !s.empty() && num[i] < s.top())
            {
                // if k greater than 0 and our stack is not empty and the upcoming digit,
                // is less than the current top than we will pop the stack top
                --k;
                s.pop();
            }
            
            s.push(num[i]);
            
            // popping preceding zeroes
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        while(k && !s.empty())
        {
            // for cases like "456" where every num[i] > num.top()
            --k;
            s.pop();
        }
        
        while(!s.empty())
        {
            res.push_back(s.top()); // pushing stack top to string
            s.pop(); // pop the top element
        }
        
        reverse(res.begin(),res.end()); // reverse the string 
        
        if(res.length() == 0)
            return "0";
        
        return res;
        
        
    }
};
	
	
// DAY 19(1675. Minimize Deviation in Array)=============================================================================================	

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set <int>  s;
        
        // Storing all  elements  in sorted order
        //insert even directly and odd with one time multiplication
        //and it will become even
        for(int i = 0; i<nums.size() ; ++i)
        {
            if(nums[i] % 2 == 0)
                s.insert(nums[i]);
            
            else
                // Odd number are transformed
                // using 2nd operation
                s.insert(nums[i] * 2);
        }
        
        // maximum - minimun
        int diff = *s.rbegin() - *s.begin();
        
        //run the loop untill difference is minimized
        while(*s.rbegin() % 2 == 0)
        {
            
            // Maximum element of the set
            int x = *s.rbegin();
            s.erase(x);
            // remove begin element and inserted half of it for minimizing
            s.insert(x/2);
            
            diff = min(diff, *s.rbegin() - *s.begin());
        }
        return diff;
    }
};


// DAY 20(1288. Remove Covered Intervals)=============================================================================================



/*

1.The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
	eg Interval [3,6] is covered by [2,8], therefore it should be removed.
	
	Let see the Number line :)
	
	                                           1  2  3  4  5  6  7  8
											   1-------4
											         3--------6
												  2-----------------8
	clearly we can see that [3 6] is covered by [2,8] and therefore it should be removed.

2. We will Sort the vector in ascending order to get this type of arrangement.
		//e.g. (1,5), (1,8), (2,9), (3,5), (4,7), (4,9)
		
3. For finding the remaining interaval, ifa[1][0] && a[1][1] both greater than a[0][0] && a[0][1],
this means the previous interval is not covered by the next one, therefore we will increase the count.
			consider the case [[1,3],[2,4],[4,8]]
								1   2  3  4  5  6  7  8
								1------3
									2-----4
									      4-----------8
											 
			No interval is completely overlaped by other therefore remainig interaval are 3.
			
			how answer is 3 , at first cnt is initialised to 1
			now a[0,0] i.e 1 and a[1,0] i.e 2   1 < 2 also,
			    a[0,1] i.e 3 and a[1,1] i.e 4   3 < 4    , therefore cnt is incremented by 2 now,
					
					also a[2,0] and a[2,1] satisy same condition with a[1,0] and a[1,1] , cnt becomes 3
					
					
					
					*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        // sorting the intervals(vector)
        sort(intervals.begin(),intervals.end());        
           
        int x1 = intervals[0][0];
        int x2 = intervals[0][1];
        
		 int res = 1;  //one for x1 and x2;
		
		// ifa[i][0] && a[i][1] both greater than a[i-1][0] && a[i-1][1]
		// increase the cnt.
        for(int i= 1; i<intervals.size(); ++i)
        {
            if(intervals[i][0] > x1 && intervals[i][1] > x2)
                ++res;
            
			// updating x1 & x2 with next intervals
			as we are comparing from upcoming ones.
            if(intervals[i][1] > x2)
            {
                x1 = intervals[i][0];
                x2 = intervals [i][1];
            }
        }
        
        return res;       // return cnt
    }

}; 


// DAY 21(169. Majority Element)=============================================================================================

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort the vector
        return nums[nums.size()/2];     // middle element will be the most frequent Element
    }
};
   



