left, right = map(int, input().split())

l, r = 0, 10 ** 9
while l + 1 < r:
    mid = (l + r) // 2
    if mid * (mid + 1) < left:
        l = mid
    else:
        r = mid
xl = r

l, r = 0, 10 ** 9
while l + 1 < r:
    mid = (l + r) // 2
    if mid * (mid + 1) <= right:
        l = mid
    else:
        r = mid
xr = l

print(xr - xl + 1)
