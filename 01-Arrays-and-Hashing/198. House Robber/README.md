<h2><a href="https://leetcode.com/problems/house-robber">198. House Robber</a></h2>

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <b>without alerting the police</b></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
</ul>


---

# 🛍️ House-Robber | Explained

## Approach 1: Space-Optimized Dynamic Programming (Iterative Bottom-Up)

### Intuition
The House Robber problem is a classic dynamic programming challenge centered around optimal decision-making with sequential constraints (no two adjacent houses can be robbed). 

Imagine walking down a street of houses. At each house $i$, you face a choice:
1. **Rob house $i$**: You gain the value at house $i$, but you cannot rob house $i-1$. Therefore, your total loot is `nums[i]` plus the maximum loot accumulated up to house $i-2$.
2. **Skip house $i$**: You gain nothing from house $i$, meaning your total loot remains the maximum loot accumulated up to house $i-1$.

Instead of storing the optimal solution for every single house in an array of size $N$ (which requires $O(N)$ auxiliary space), we only ever need the optimal loot values from the **previous two houses** ($i-1$ and $i-2$). By maintaining just two dynamic variables (`dpzero` representing $i-2$ and `dpone` representing $i-1$), we reduce space complexity from $O(N)$ down to $O(1)$ while maintaining linear time complexity.

### Algorithm Visualized

```mermaid
graph TD
    A[Start at House i] --> B{Decision at House i}
    B -->|Option 1: Rob House i| C[Loot = nums[i] + dpzero]
    B -->|Option 2: Skip House i| D[Loot = dpone]
    C --> E[New Max Loot = max Option 1, Option 2]
    D --> E
    E --> F[Update State: dpzero = dpone]
    F --> G[Update State: dpone = New Max Loot]
    G --> H[Advance to House i+1]
```

---

### Approach
1. **Edge Case Handling**:
   - If there is only $1$ house, return `nums[0]`.
   - If there are only $2$ houses, return `max(nums[0], nums[1])`.
2. **Base State Initialization**:
   - Set `dpzero` to `nums[0]` (max loot up to index 0).
   - Set `dpone` to `max(nums[0], nums[1])` (max loot up to index 1).
3. **State Transition Loop**:
   - Iterate from index $i = 2$ to $N - 1$.
   - Calculate `take = nums[i] + dpzero`.
   - Calculate `skip = dpone`.
   - Update `dpzero = dpone` (shift state window forward).
   - Update `dpone = max(take, skip)` (store optimal choice for current state).
4. **Result**: Return `dpone`, which holds the optimal value after evaluating all houses.

---

### Detailed Code Analysis

- **Lines 3–4**: Edge cases are handled immediately with $O(1)$ early returns, eliminating redundant loop iterations and potential out-of-bounds access.
  ```cpp
  if(nums.size()==1) return nums[0];
  if(nums.size()==2) return max(nums[0],nums[1]);
  ```
- **Lines 6–7**: State variable initialization establishing the base cases for subproblems of size 1 and size 2.
  ```cpp
  int dpzero=nums[0];
  int dpone=max(nums[0],nums[1]);
  ```
- **Line 10**: Single linear scan ($O(N)$ time) iterating through remaining elements starting at index 2.
  ```cpp
  for(int i=2;i<nums.size();i++){
  ```
- **Lines 11–12**: Explicit calculation of choice choices reflecting the recurrence relation $DP[i] = \max(nums[i] + DP[i-2], DP[i-1])$.
  ```cpp
  int take=nums[i]+dpzero;
  int skip=dpone;
  ```
- **Lines 14–15**: Rolling variable technique to maintain state using constant space ($O(1)$ memory).
  ```cpp
  dpzero=dpone;
  dpone=max(take,skip);
  ```
- **Line 17**: Returns the ultimate state value corresponding to the maximum achievable loot for the entire array.

---

### Code

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        int dpzero=nums[0];
        int dpone=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int take=nums[i]+dpzero;
            int skip=dpone;

            dpzero=dpone;
            dpone=max(take,skip);
        }
        return dpone;
    }
};
```

---

### Complexity

- **Time Complexity:** $\mathcal{O}(N)$  
  The solution traverses the array of size $N$ exactly once in a single sequential loop. Operations inside the loop are executed in constant time $\mathcal{O}(1)$.
  
- **Space Complexity:** $\mathcal{O}(1)$  
  The implementation optimizes the standard dynamic programming solution by replacing an $\mathcal{O}(N)$ tabular array with two primitive scalar variables (`dpzero` and `dpone`), resulting in optimal constant memory utilization.

---

## 🕵️‍♂️ Follow-up Questions

### 1. What if the houses are arranged in a circle (House Robber II)?
**Answer:** If houses are arranged in a circle, the first and last houses are adjacent, meaning you cannot rob both. To solve this, run the state-optimized dynamic programming function twice:
1. From index $0$ to $N-2$ (including the first house, excluding the last).
2. From index $1$ to $N-1$ (excluding the first house, including the last).

The global maximum will be $\max(\text{Rob}(0, N-2), \text{Rob}(1, N-1))$.

### 2. How would you reconstruct the actual indices of the houses that were robbed?
**Answer:** Optimizing space to $O(1)$ discards history needed for backtracking. To reconstruct the optimal set of house indices:
- Maintain an $O(N)$ dynamic programming table or track parent choices via a backtrack array/boolean decision matrix.
- Traverse backward from index $N-1$: if $DP[i] == DP[i-1]$, house $i$ was skipped; if $DP[i] == nums[i] + DP[i-2]$, house $i$ was robbed, and we step back to $i-2$.