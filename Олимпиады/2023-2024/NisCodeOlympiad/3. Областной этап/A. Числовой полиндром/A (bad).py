def f(num):
    num = str(num)
    l = len(num)
    for i in range(l // 2):
        if num[i] != num[l - 1 - i]:
            return False
    return True

n = int(input())
n += 1
while not f(n):
    n += 1
print(n)
