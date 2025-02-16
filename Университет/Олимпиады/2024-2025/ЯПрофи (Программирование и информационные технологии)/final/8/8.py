n = int(input())
cnt = [0] * 10
for x in range(1, n + 1):
    for d in range(10):
        cnt[d] += str(x).count(str(d))
print(cnt)
