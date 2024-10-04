vowels = set('aeiou')

S = input()

cnt = 0
for c in S:
    if c in vowels:
        cnt += 1

print(cnt)
