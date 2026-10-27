# Just Draw a L, one liner solution

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

Just drawing L will stisfy the problem statement

```
. # # # # # # # # # #
. # # # # # # # # # #
. # # # # # # # # # #
. # # # # # # # # # #
. # # # # # # # # # #
. # # # # # # # # # #
. # # # # # # # # # #
. . . . . . . . . . .
```

# Complexity
- Time complexity:
$$O(m+n)$$

- Space complexity:
$$O(m*n)$$

# Code
```python3 []
class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        return [f".{'#'*(n-1)}"] * (m-1) + ['.'*n]
        
```