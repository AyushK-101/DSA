<h2><a href="https://leetcode.com/problems/unique-paths">62. Unique Paths</a></h2>

<p>There is a robot on an <code>m x n</code> grid. The robot is initially located at the <strong>top-left corner</strong> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>

<p>Given the two integers <code>m</code> and <code>n</code>, return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>

<p>The test cases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;">
<pre><strong>Input:</strong> m = 3, n = 7
<strong>Output:</strong> 28
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right
3. Down -&gt; Right -&gt; Down
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>


---

# 🛍️ Unique-Paths | Explained

## Approach 1: Combinatorics (Math)

### Intuition
Total steps = $m+n-2$. Selecting $m-1$ down moves gives combinations $\binom{m+n-2}{m-1}$.

### Approach
Compute factorial ratio $\frac{\text{sum}!}{\text{maxi}! \times \text{diff}!}$ using floating-point loops to prevent overflow.

### Detailed Code Analysis
- `sum`: Total path moves.
- `upper`: Numerator product from `maxi+1` to `sum`.
- `lower`: Denominator product for remaining factorial.
- Returns `upper/lower`.

### Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum=m+n-2, maxi=max(m-1,n-1);
        double upper=1, lower=1;
        for(int i=sum; i>maxi; i--) upper*=i;
        for(int i=sum-maxi; i>1; i--) lower*=i;
        return upper/lower;
    }
};
```

### Complexity
- **Time:** $O(\min(m, n))$
- **Space:** $O(1)$