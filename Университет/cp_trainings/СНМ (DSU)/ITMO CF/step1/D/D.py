class DSU(object):
    def __init__(self, n: int) -> None:
        self.p = [i for i in range(n + 1)]
        self.size = [1] * (n + 1)
        return
    
    def get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.get(self.p[a])
        return self.p[a]
    
    def union(self, a: int, b: int) -> None:
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.p[b] = a
        self.size[a] += self.size[b]
        return

def main() -> None:
    n, m, k = map(int, input().split())
    for _ in range(m):
        input()
    qs = []
    conv = lambda l: (l[0], int(l[1]), int(l[2]))
    for _ in range(k):
        qs.append(conv(input().split()))
    
    qs.reverse()
    ress = []
    dsu = DSU(n)    
    for cmd, u, v in qs:
        if cmd == 'ask':
            ress.append('YES' if dsu.get(u) == dsu.get(v) else 'NO')
        else: # cmd == 'cut'
            dsu.union(u, v)
    ress.reverse()
    print('\n'.join(ress))
    return

if __name__ == '__main__':
    main()
