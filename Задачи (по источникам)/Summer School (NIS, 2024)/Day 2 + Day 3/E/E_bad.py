# This solution's acymptotic is O(n ** 2) where n = |s|
# P.S.: this solution has verdict 'OK' ('Accepted') but this is only because of bad tests

s = input()
n = len(s)

ans = 0

for i in range(n):
    d = {}
    for j in range(i, n):
        d[s[j]] = d.get(s[j], 0) + 1

        vals = list(d.values())
        odds = 0
        for val in vals:
            if val % 2 == 1:
                odds += 1
        if odds in [0, 1]:
            ans += 1

print(ans)
