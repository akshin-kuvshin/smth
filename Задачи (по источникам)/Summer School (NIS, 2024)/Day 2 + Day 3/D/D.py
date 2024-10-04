a, b = map(int, input().split())

if abs(a - b) % 3 != 0:
    print(-1)
else:
    print(min(a, b) // 3 * 2 + min(a, b) % 3 + abs(a - b) // 3)
