# 0/1 knapsack using dynamic programming

## Explaination

Dynamic Programming approach divides the problem to be solved into subproblems.

The subproblems are further kept on dividing into smaller subproblems.

Until you get subproblems that can be solved easily.
The idea of Knapsack dynamic programming is to use a table to store the solutions of solved subproblems.

In the table, all the possible weights from `1` to `W` serve as the columns and weights are kept as the rows.

The state DP[i][j] in the above example denotes the maximum value of `j-weight` considering all values from `1 to ith`.

So if we consider `wi` (weight in `ith` row) it is put in all columns which have `weight values > wi`.

Two possibilities occur – to fill or not to fill `wi` in the given column. If we do not fill `ith` weight in `jth` column then DP[i][j] state will be same as DP[i-1][j].

But if we fill the weight, DP[i][j] will be equal to the value of `wi`+ value of the column weighing `j-wi` in the previous row.

We therefore take the maximum of these two possibilities to fill the current state.

## Attribution

https://www.pythonpool.com/knapsack-problem-python/
