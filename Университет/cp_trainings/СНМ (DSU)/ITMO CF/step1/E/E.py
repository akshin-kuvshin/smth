class DSU(object):
    def __init__(self, n: int) -> None:
        self.l = [[i] for i in range(n)]
        self.p = [i for i in range(n)]
        self.size = [1] * n
        return
    
    def get(self, a: int) -> int:
        return self.p[a]
    
    def union(self, a: int, b: int) -> None: # works ~ for O(logn)
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.l[a].extend(self.l[b])
        for u in self.l[b]:
            self.p[u] = a
        self.size[a] += self.size[b]
        return
    
    def get_comp(self, a: int) -> list[int]:
        a = self.get(a)
        return self.l[a].copy()

def main() -> None:
    n, m = map(int, input().split())
    tree = []
    G = [[] for _ in range(n)] # список смежностей
    for u in range(n):
        l, r = map(int, input().split())
        if l != -1:
            l -= 1
            G[u].append(l)
        if r != -1:
            r -= 1
            G[u].append(r)
        tree.append({
            'l': l,
            'r': r
        })
    qs = []
    for _ in range(m):
        u, h = map(int, input().split())
        u -= 1
        h = ('l' if h == 1 else 'r')
        G[u].remove(tree[u][h])
        qs.append((u, h))
    
    dsu = DSU(n)
    for u in range(n):
        for v in G[u]:
            dsu.union(u, v)
    del G

    ress = [-1] * n
    for t in range(m - 1, -1, -1):
        u, h = qs[t]
        v = tree[u][h]

        if dsu.get(u) != dsu.get(0) and dsu.get(v) != dsu.get(0):
            if dsu.get(u) != dsu.get(v):
                dsu.union(u, v)
        elif dsu.get(u) != dsu.get(0) or dsu.get(v) != dsu.get(0):
            if dsu.get(u) != dsu.get(0):
                u, v = v, u
            l = dsu.get_comp(v)
            for ind in l:
                ress[ind] = t
            dsu.union(u, v)
    print('\n'.join(list(map(str, ress))))
    return

if __name__ == '__main__':
    main()
