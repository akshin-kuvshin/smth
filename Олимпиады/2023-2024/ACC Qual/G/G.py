n, m = map(int, input().split())
matrix = [input().split() for _ in range(n)]

l = int(input())
s = input()

#jxxuuxjxxuux
dict_pos = {}
for i in range(n):
    for j in range(m):
        dict_pos[matrix[i][j]] = (i, j)

ds = s * 2
y, x = dict_pos[s[0]]
steps = [1]
for letter in ds[1:]:
    step = 1
    to_y, to_x = dict_pos[letter]
    step += abs(to_y - y) + abs(to_x - x)
    x, y = to_x, to_y
    steps.append(steps[-1] + step)

ans = float('inf')
left, r = 0, l - 1
while r < len(ds):
    total = steps[r] - steps[left] + 1
    if total < ans:
        ans = total
    left += 1
    r += 1

print(ans)
