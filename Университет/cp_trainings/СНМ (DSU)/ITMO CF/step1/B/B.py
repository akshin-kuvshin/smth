class DSU:
    def __init__(self, n: int) -> None:
        self.p = [i for i in range(n)]
        self.min = self.p.copy()
        self.max = self.p.copy()
        self.size = [1] * n
        return
    
    def get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.get(self.p[a])
        return self.p[a]
    
    def min_max_size(self, a: int) -> dict[str, int]:
        a = self.get(a)
        return {
            'min': self.min[a],
            'max': self.max[a],
            'size': self.size[a]
        }
    
    def union(self, a: int, b: int) -> None:
        a = self.get(a)
        b = self.get(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.p[b] = a
        self.min[a] = min(self.min[a], self.min[b])
        self.max[a] = max(self.max[a], self.max[b])
        self.size[a] += self.size[b]
        return

def main() -> None:
    n, q = map(int, input().split())
    dsu = DSU(n)
    for _ in range(q):
        inputs = input().split()
        if inputs[0] == 'union':
            u, v = int(inputs[1]) - 1, int(inputs[2]) - 1
            dsu.union(u, v)
        else: # inputs[0] == 'get'
            a = int(inputs[1]) - 1
            t = dsu.min_max_size(a)
            print(t['min'] + 1, t['max'] + 1, t['size'])
    return

if __name__ == '__main__':
    main()
