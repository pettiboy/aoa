def lcs_algo(s1, s2, m, n):
    mat = [[0 for _ in range(n+1)] for _ in range(m+1)]

    # Building the mtrix in bottom-up way
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                mat[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                mat[i][j] = mat[i-1][j-1] + 1
            else:
                mat[i][j] = max(mat[i-1][j], mat[i][j-1])

    index = mat[m][n]

    result = [""] * (index+1)

    i = m
    j = n
    while i > 0 and j > 0:

        if s1[i - 1] == s2[j - 1]:
            result[index - 1] = s1[i - 1]
            i -= 1
            j -= 1
            index -= 1

        elif mat[i - 1][j] > mat[i][j - 1]:
            i -= 1
        else:
            j -= 1

    print("LCS: " + "".join(result))


def main():
    S1 = input("S1: ")
    S2 = input("S2: ")
    m = len(S1)
    n = len(S2)
    lcs_algo(S1, S2, m, n)


if __name__ == '__main__':
    main()
