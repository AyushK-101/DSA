1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        int sum=m+n-2;
5        int maxi=max(m-1,n-1);
6        double upper=1,lower=1;
7
8        for(int i=sum;i>maxi;i--){
9            upper*=i;
10        }
11        int diff=sum-maxi;
12        for(int i=diff;i>1;i--){
13            lower*=i;
14        }
15        return upper/lower;
16    }
17};