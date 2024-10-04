from string import ascii_lowercase

S = input()

letters_cnt = {}
odd_letters_on_pref = []

odd_letters_on_pref.append(set())
for c in S:
    letters_cnt[c] = letters_cnt.get(c, 0) + 1
    odd_letters_on_pref.append(set())
    for _c in ascii_lowercase:
        if letters_cnt.get(_c, 0) % 2 == 1:
            odd_letters_on_pref[-1].add(_c)

distinct_prefs_cnt = {}
ans = 0

for odd_letters in odd_letters_on_pref:
    frozed_elem = frozenset(odd_letters)
    ans += distinct_prefs_cnt.get((frozed_elem, False), 0) + distinct_prefs_cnt.get((frozed_elem, True), 0)
    distinct_prefs_cnt[(frozed_elem, False)] = distinct_prefs_cnt.get((frozed_elem, False), 0) + 1
    for c in odd_letters:
        without_c = odd_letters.copy()
        without_c.remove(c)
        frozed_without_c = frozenset(without_c)
        ans += distinct_prefs_cnt.get((frozed_without_c, False), 0)
        distinct_prefs_cnt[(frozed_without_c, True)] = distinct_prefs_cnt.get((frozed_without_c, True), 0) + 1

print(ans)
