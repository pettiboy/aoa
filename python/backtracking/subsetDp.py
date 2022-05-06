def isSubsetSum(arr, n, useSum):

    dp = ([[False for i in range(useSum + 1)]
          for i in range(n + 1)])

    for i in range(n + 1):
        dp[i][0] = True

    for i in range(1, useSum + 1):
        dp[0][i] = False

    for i in range(1, n + 1):
        for j in range(1, useSum + 1):
            if j < arr[i-1]:
                dp[i][j] = dp[i-1][j]
            if j >= arr[i-1]:
                dp[i][j] = (dp[i-1][j] or
                            dp[i - 1][j-arr[i-1]])

    return dp[n][useSum]


def main():
    # Driver program to test above function
    arr = [3, 34, 4, 12, 5, 2]
    useSum = 9
    n = len(arr)
    if (isSubsetSum(arr, n, useSum) == True):
        print("Found a subset with given sum")
    else:
        print("No subset with given sum")


if __name__ == '__main__':
    main()
