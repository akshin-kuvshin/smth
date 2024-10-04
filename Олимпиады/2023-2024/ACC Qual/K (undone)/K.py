n, m = map(int, input().split())
ma, mi = 0, float('inf')

a = []
for _ in range(n):
    num, s = input().split()
    if '<=' == s and int(num) > ma:
        mi = int(num)
    elif '>=' == s and int(num) < mi:
        ma = int(num)
    a.append((int(num), s))

b = []
for _ in range(m):
    num, s = input().split()
    if '<=' == s and int(num) > ma:
        mi = int(num)
    elif '>=' == s and int(num) < mi:
        ma = int(num)
    b.append((int(num), s))

def true_or_false(num, s) -> bool:
    if s == '<=':
        return num <= mi
    else:
        return num >= ma

new = list(map(lambda x: true_or_false(num=x[0], s=x[1]), a[:]))
print(ma, mi)
print(a)
print(b)
print(new)
for i in range(m):
    a.append(true_or_false(b[i][0], b[i][1]))
    print(min(new.count(True), new.count(False)))
