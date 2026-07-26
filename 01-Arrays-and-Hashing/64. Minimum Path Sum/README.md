<h2><a href="https://leetcode.com/problems/minimum-path-sum">64. Minimum Path Sum</a></h2>

<p>Given a <code>m x n</code> <code>grid</code> filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>

<p><strong>Note:</strong> You can only move either down or right at any point in time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 200</code></li>
</ul>


---

# 🛍️ Minimum-Path-Sum | Explained

## Approach 1: In-Place Dynamic Programming
### Intuition
Find the minimum path sum to each cell by choosing the smaller sum between its top and left neighbors.

### Approach
1. Accumulate prefix sums for the first column and row.
2. Update remaining cells: `grid[i][j] += min(above, left)`.

### Detailed Code Analysis
- **Lines 4–9:** Fill boundary accumulated sums.
- **Lines 11–15:** Transition state using `min(grid[i-1][j], grid[i][j-1])`.

### Code
```cpp
int minPathSum(vector<vector<int>>& grid) {
    for(int i=1;i<grid.size();i++) grid[i][0]+=grid[i-1][0];
    for(int j=1;j<grid[0].size();j++) grid[0][j]+=grid[0][j-1];
    for(int i=1;i<grid.size();i++)
        for(int j=1;j<grid[0].size();j++)
            grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
    return grid.back().back();
}
```

### Complexity
- **Time:** $\mathcal{O}(M \times N)$
- **Space:** $\mathcal{O}(1)$