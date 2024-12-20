class DSU(object):
    def __init__(self, n: int) -> None:
        self.p = list(range(n + 1))
        self.d = [0] * (n + 1)
        return
    
    def __get(self, a: int) -> tuple[int, int]:
        if self.p[a] == a:
            return (a, 0)
        par, depth = self.__get(self.p[a])
        self.p[a] = par
        self.d[a] += depth
        return (self.p[a], self.d[a])

    def unite(self, a: int, b: int) -> None:
        self.p[a] = b
        self.d[a] += 1
        return
    
    def get_d(self, c: int) -> int:
        return self.__get(c)[1]

def main() -> None:
    n, m = map(int, input().split())

    dsu = DSU(n)
    for _ in range(m):
        a = list(map(int, input().split()))
        if a[0] == 1:
            dsu.unite(a[1], a[2])
        else: # a[0] == 2
            print(dsu.get_d(a[1]))
    return

if __name__ == '__main__':
    main()
