S: str = input()

ans: str = S[0]
new_sentence: bool = False
was_upper: bool = True
for c in S[1 : len(S) - 1]:
    if c.islower():
        ans += c
        new_sentence = False
        was_upper = False
    elif c.isupper():
        if new_sentence:
            ans += ' ' + c
            new_sentence = False
            was_upper = True
        elif not was_upper:
            ans += ' ' + c.lower()
            new_sentence = False
            was_upper = True
        else: # was_upper
            ans = ans[0 : len(ans) - 1] + ans[-1].upper() + c.lower()
            new_sentence = False
            was_upper = False
    elif c == '.':
        ans += ','
        new_sentence = False
        was_upper = False
    elif c == ',':
        ans += '.'
        new_sentence = True
        was_upper = False
    else: # c == '?' or c == '!'
        ans += c
        new_sentence = True
        was_upper = False
ans += S[-1]

print(ans)
