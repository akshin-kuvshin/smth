class DSU(object):
    def __init__(self, n: int) -> None:
        self.p = list(range(n + 1))
        self.size = [1] * (n + 1)
        return
    
    def __get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.__get(self.p[a])
        return self.p[a]
    
    def unite(self, a: int, b: int) -> None:
        a = self.__get(a)
        b = self.__get(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.p[b] = a
        self.size[a] += self.size[b]
        return
    
    def eq(self, a: int, b: int) -> bool:
        return self.__get(a) == self.__get(b)

def main() -> None:
    n, m = map(int, input().split())
    ribs = []
    for _ in range(m):
        u, v, d = map(int, input().split())
        ribs.append((d, u, v))
    ribs.sort()

    dsu = DSU(n)
    ans = cnt = 0
    for d, u, v in ribs:
        if cnt == n - 1:
            break
        if dsu.eq(u, v):
            continue
        dsu.unite(u, v)
        ans += d
        cnt += 1
    print(ans)
    return

if __name__ == '__main__':
    main()
