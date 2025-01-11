import operator as op
INF = 2 * 10 ** 9 + 29

class DSU:
    def __init__(self, orsize: int) -> None:
        self.size = orsize
        self.clear()
        return
    
    def clear(self) -> None:
        self.p = list(range(self.size))
        self.r = [0] * self.size
        return
    
    def get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.get(self.p[a])
        return self.p[a]
    
    def unite(self, a: int, b: int) -> None:
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return
        if self.r[a] == self.r[b]:
            self.r[a] += 1
        if self.r[a] > self.r[b]:
            self.p[b] = a
        else: # self.r[a] < self.r[b]
            self.p[a] = b
        return

def main() -> None:
    n, m = map(int, input().split())
    ribs = []
    for _ in range(m):
        u, v, w = map(int, input().split())
        ribs.append((u - 1, v - 1, w))
    ribs.sort(key=op.itemgetter(-1))
    
    dsu = DSU(n)
    min_d = INF
    for i in range(m):
        dsu.clear()
        _min = INF
        _max = -INF
        cnt = 0
        for j in range(i, m):
            if cnt == n - 1:
                break
            if dsu.get(ribs[j][0]) == dsu.get(ribs[j][1]):
                continue
            dsu.unite(ribs[j][0], ribs[j][1])
            _min = min(_min, ribs[j][-1])
            _max = max(_max, ribs[j][-1])
            cnt += 1
        if cnt == n - 1:
            min_d = min(min_d, _max - _min)
    
    if min_d == INF: # there is no MST (minimal spanning tree)
        print('NO')
    else: # there is at least one MST
        print(f'YES\n{min_d}')

    return

if __name__ == '__main__':
    main()
