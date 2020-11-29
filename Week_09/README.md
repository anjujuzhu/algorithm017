学习笔记
- DP顺推模板
```python
function DP():
    dp = [][] #二维情况

    for i = 0...M {
        for j = 0...N {
            dp[i][j] = _Function(dp[i1][j1]...)
        }
    }

    return dp[M][N];
```
- 高阶DP
 1. 状态拥有更多维度
 2. 状态方程更加复杂

 - 一维的情况下无法写出dp方程就考虑增加一维

- 字符串
 - python java的string是immutable, 字符串+char之后是新生成一个string
 - C++ 是在原来的string上操作