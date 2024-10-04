def main():
    n = int(input())
    SAT = [input().split() for _ in range(n)]

    letters = set()
    for s in SAT:
        c1, c2 = s
        c1 = c1.strip('!')
        c2 = c2.strip('!')

        letters.add(c1)
        letters.add(c2)

    for c in letters:
        for s in SAT:
            if [c, c] == s or ['!' + c, '!' + c] == s:
                return 'Plad'
        
        d = set()
        nd = set()
        for s in SAT:
            if s in [[c, '!' + c], ['!' + c, c]]:
                continue
            if c not in [_s.strip('!') for _s in s]:
                continue
            if c == s[1].strip('!'):
                s.reverse()
            
            if s[0][0] == '!':
                nd.add(frozenset(s))
            else: # s[0][0] != '!'
                d.add(frozenset(s))
        
        if len(d) > 1 or len(nd) > 1:
            return 'Plad'
    
    for e1 in SAT:
        for e2 in SAT:
            if ('!' + e1[0] == e2[0] or e1[0] == '!' + e2[0]) and e1[1].strip('!') != e2[1].strip('!'):
                if e1[0][0] == '!':
                    if e1[0] != '!' + e1[1] and '!' + e2[0] != e2[1]:
                        return 'Plad'
                else: # e2[0][0] == '!'
                    if e2[0] != '!' + e2[1] and '!' + e1[0] != e1[1]:
                        return 'Plad'
            e2.reverse()
            if ('!' + e1[0] == e2[0] or e1[0] == '!' + e2[0]) and e1[1].strip('!') != e2[1].strip('!'):
                if e1[0][0] == '!':
                    if e1[0] != '!' + e1[1] and '!' + e2[0] != e2[1]:
                        return 'Plad'
                else: # e2[0][0] == '!'
                    if e2[0] != '!' + e2[1] and '!' + e1[0] != e1[1]:
                        return 'Plad'
    
    return 'Zhnri'

print(main())
