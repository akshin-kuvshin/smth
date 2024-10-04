def count_inv(l):
    res = 0
    ones = 0
    for b in l:
        if b == 1:
            ones += 1
        else: # b == 0
            res += ones
    return res

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

print(abs(count_inv(a) - count_inv(b)))
