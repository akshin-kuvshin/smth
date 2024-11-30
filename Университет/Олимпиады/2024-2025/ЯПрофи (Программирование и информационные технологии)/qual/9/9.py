def main() -> None:
    s = input()
    n = len(s)

    dp = [[0] * 3 for _ in range(n)]
    if s[0] == '1': # раньше здесь было "s[i] == 1"...
        dp[0][0] = 1
    else: # s[0] == 0
        dp[0][1] = 1
    
    for i in range(1, n):
        if s[i] == '1': # раньше здесь тоже было "s[i] == 1"...
            dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1] + 1) % MOD
            dp[i][1] = dp[i - 1][1]
            dp[i][2] = (2 * dp[i - 1][2]) % MOD
        else: # s[i] == '0'
            dp[i][0] = dp[i - 1][0]
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + 1) % MOD
            dp[i][2] = (dp[i - 1][1] + 2 * dp[i - 1][2]) % MOD

    print(dp[n - 1][2])
    return

if __name__ == '__main__':
    MOD = 10 ** 9 + 7
    C = int(input())
    for _ in range(C):
        main()
