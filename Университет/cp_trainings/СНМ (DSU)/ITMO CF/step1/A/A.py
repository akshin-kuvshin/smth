class DSU:
    def __init__(self, n: int) -> None:
        self.p = [i for i in range(n)]
        self.size = [1] * n
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
    n, q = map(int, input().split())
    dsu = DSU(n)
    for _ in range(q):
        cmd, u, v = input().split()
        u, v = int(u) - 1, int(v) - 1
        if cmd == 'union':
            dsu.union(u, v)
        else: # cmd == 'get'
            print('YES' if dsu.get(u) == dsu.get(v) else 'NO')
    return

if __name__ == '__main__':
    main()
