<h2><a href="https://leetcode.com/problems/house-robber-ii">213. House Robber II</a></h2>

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are <strong>arranged in a circle.</strong> That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and&nbsp;<b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <strong>without alerting the police</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


---

# 🛍️ House-Robber-II | Explained

## Approach 1: Two-Pass Space-Optimized DP
### Intuition
Houses form a circle, so house `0` and `n-1` are adjacent. We split the problem into two linear subproblems: robbing houses `0` to `n-2` OR `1` to `n-1`.

### Approach
1. Handle base cases ($N \le 2$).
2. Pass 1: DP on range `0` to `n-2` using rolling variables (`dpzero`, `dpone`).
3. Pass 2: DP on range `1` to `n-1` using rolling variables (`dpuno`, `dpdos`).
4. Return `max(dpone, dpdos)`.

### Complexity
- **Time:** $O(N)$ — Two linear iterations.
- **Space:** $O(1)$ — Uses scalar variables instead of a DP table.