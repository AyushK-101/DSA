<h2><a href="https://leetcode.com/problems/unique-paths-ii">63. Unique Paths II</a></h2>

<p>You are given an <code>m x n</code> integer array <code>grid</code>. There is a robot initially located at the <b>top-left corner</b> (i.e., <code>grid[0][0]</code>). The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.</p>

<p>An obstacle and space are marked as <code>1</code> or <code>0</code> respectively in <code>grid</code>. A path that the robot takes cannot include <strong>any</strong> square that is an obstacle.</p>

<p>Return <em>the number of possible unique paths that the robot can take to reach the bottom-right corner</em>.</p>

<p>The testcases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right -&gt; Right
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;">
<pre><strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == obstacleGrid.length</code></li>
	<li><code>n == obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
</ul>


---

# 🛍️ Unique-Paths-II | Explained

## Approach 1: Dynamic Programming
### Intuition
Accumulate paths from adjacent cells, zeroing path counts at obstacles.

### Algorithm Visualized
```mermaid
graph LR
A[Top/Left Cell] -->|No Obstacle| B[Current Cell]
```

### Approach
Validate origin, then set first column path values using a flag.

### Detailed Code Analysis
The code checks for an origin obstacle (`obstacleGrid[0][0]==1`) and updates first-column path counts (`ways[i][0]`) using `rowflag` to block paths after any obstacle.

### Code
```cpp
if (obstacleGrid[0][0] == 1) return 0;
int rowflag = 0;
for(int i = 0; i < obstacleGrid.size(); i++) {
    if(obstacleGrid[i][0] == 1) rowflag = 1;
    ways[i][0] = !rowflag;
}
```

### Complexity
- **Time:** $O(M \times N)$
- **Space:** $O(M \times N)$