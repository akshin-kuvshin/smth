q = input()
q_len = len(q)

raw_S = input()
raw_S_len = len(raw_S)

S = ''
can_be_zero = []
i = 0
while i < raw_S_len:
    if raw_S[i] == ' ':
        i += 1
        continue
    S += raw_S[i]
    can_be_zero.append(True)
    if (i == 0 or raw_S[i - 1] == ' ') and not (i == raw_S_len - 1 or raw_S[i + 1] == ' '):
        can_be_zero[-1] = False
    i += 1
del i

S_len = len(S)
crossed_out = [False] * S_len
i = 0
while i + q_len <= S_len:
    if S[i:(i + q_len)] == q:
        crossed_out[i:(i + q_len)] = [True] * q_len
    i += 1
del i

new_S = ''
i = 0
while i < S_len:
    if not crossed_out[i]:
        new_S += S[i]
        i += 1
        continue

    next_i = i + 1
    while next_i < S_len and not crossed_out[next_i]:
        next_i += 1

    for d in range(0, 3):
        if d == 0 and not can_be_zero[i]:
            continue
        if (new_S + str(d) + S[(i + 1):next_i]).find(q) == -1:
            new_S += str(d) + S[(i + 1):next_i]
            break
        
    i = next_i
del i

i = 0
for c in raw_S:
    if c == ' ':
        print(' ', end='')
    else:
        print(new_S[i], end='')
        i += 1
del i
print()
