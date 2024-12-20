def count(S):
    E = []
    cur = ''
    for c in S:
        if c == '+' or c == '-':
            E.append(cur)
            cur = ''
            E.append(c)
        else: # c is digit
            cur += c
    E.append(cur)
    del cur
    
    if E[0] == '':
        return None
    if len(E[0]) > 1 and E[0][0] == '0':
        return None
    if len(E[0]) > 10:
        return None
    res = int(E[0])
    for e in E[1:]:
        if e == '+':
            plus = True
        elif e == '-':
            plus = False
        else: # e is number in string
            if e == '':
                return None
            if len(e) > 1 and e[0] == '0':
                return None
            if len(e) > 10:
                return None
            if plus:
                res += int(e)
            else: # not plus === minus
                res -= int(e)
    return res

def main():
    L, R = input().split('=')
    
    if count(L) == count(R):
        print('Correct')
        return
    
    for i in range(len(L)):
        if L[i] == '+' or L[i] == '-':
            continue
        Lc = L[:i] + L[i + 1:]
        Rc = R
        for j in range(len(Lc)):
            Lc = Lc[:j] + L[i] + Lc[j:]
            res_L = count(Lc)
            res_R = count(Rc)
            if res_L is None:
                Lc = L[:i] + L[i + 1:]
                continue
            if res_R is None:
                Lc = L[:i] + L[i + 1:]
                continue
            if res_L == res_R:
                print(Lc, Rc, sep='=')
                return
            Lc = L[:i] + L[i + 1:]
        for j in range(len(Rc)):
            Rc = Rc[:j] + L[i] + Rc[j:]
            res_L = count(Lc)
            res_R = count(Rc)
            if res_L is None:
                Rc = R
                continue
            if res_R is None:
                Rc = R
                continue
            if res_L == res_R:
                print(Lc, Rc, sep='=')
                return
            Rc = R
    for i in range(len(R)):
        if R[i] == '+' or R[i] == '-':
            continue
        Lc = L
        Rc = R[:i] + R[i + 1:]
        for j in range(len(Lc)):
            Lc = Lc[:j] + R[i] + Lc[j:]
            res_L = count(Lc)
            res_R = count(Rc)
            if res_L is None:
                Lc = L
                continue
            if res_R is None:
                Lc = L
                continue
            if res_L == res_R:
                print(Lc, Rc, sep='=')
                return
            Lc = L
        for j in range(len(Rc)):
            Rc = Rc[:j] + R[i] + Rc[j:]
            res_L = count(Lc)
            res_R = count(Rc)
            if res_L is None:
                Rc = R[:i] + R[i + 1:]
                continue
            if res_R is None:
                Rc = R[:i] + R[i + 1:]
                continue
            if res_L == res_R:
                print(Lc, Rc, sep='=')
                return
            Rc = R[:i] + R[i + 1:]
    
    print('Impossible')
    return

if __name__ == '__main__':
    main()