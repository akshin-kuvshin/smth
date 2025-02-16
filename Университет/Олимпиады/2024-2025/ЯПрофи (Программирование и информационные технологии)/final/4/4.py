L = 'abcd'
T = 'efgh'
V = 'i'
S = 'j'
M = 'kl'

orig = L + T + V + S + M
orig_sets = [set() for _ in range(4)]
for i in range(4):
    for j in range(len(orig) - i):
        orig_sets[i].add(orig[j : j + i + 1])

texts = [
    L + T + V + M + S,
    T + L + V + M + S,
    T + V + M + S + L,
    T + V + S + M + L,
    L + V + M + S + T,
    L + V + S + M + T
]

for text_id in range(len(texts)):
    text = texts[text_id]
    text_sets = [set() for _ in range(4)]
    for i in range(4):
        for j in range(len(text) - i):
            text_sets[i].add(text[j : j + i + 1])
    
    intersects = []
    for i in range(4):
        intersects.append(len(orig_sets[i] & text_sets[i]))
    
    res = 1.
    for i in range(4):
        res *= intersects[i] / len(orig_sets[i])
    res *= 100
    print(text_id + 1, intersects, res)
