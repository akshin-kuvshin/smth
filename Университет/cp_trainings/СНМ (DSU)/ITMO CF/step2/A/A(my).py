class DSU(object):
    __INF: int = 1_000_000_000

    def __init__(self, n: int) -> None:
        n += 2
        self.p = [i for i in range(n)]
        self.size = [1] * n
        self.right = [i for i in range(n)]
        self.right[-1] = self.__INF
        return
    
    def __get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.__get(self.p[a])
        return self.p[a]
    
    def __union(self, a: int, b: int) -> None:
        a = self.__get(a)
        b = self.__get(b)
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.p[b] = a
        self.size[a] += self.size[b]
        self.right[a] = max(self.right[a], self.right[b])
        return
    
    def kill(self, a: int) -> None:
        self.__union(a, a + 1)
        return
    
    def get_right(self, a: int) -> int:
        a = self.__get(a)
        return (self.right[a] if self.right[a] < self.__INF else -1)

def main() -> None:
    n, q = map(int, input().split())

    dsu = DSU(n)
    for _ in range(q):
        cmd, a = input().split()
        a = int(a)
        if cmd == '-':
            dsu.kill(a)
        else: # cmd == '?'
            print(dsu.get_right(a))
    
    return

if __name__ == '__main__':
    main()
