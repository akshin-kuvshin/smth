class DSU(object):
    def __init__(self, n: int) -> None:
        self.n = n
        self.p = list(range(self.n + 1))
        return
    
    def get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.get(self.p[a])
        return self.p[a]
    
    def kill(self, a: int) -> None:
        if a == self.n:
            self.p[self.n] = 1
            return
        self.p[a] = a + 1
        return

def main() -> None:
    n = int(input())
    drivers = map(int, input().split())

    dsu = DSU(n)
    for wanted_place in drivers:
        real_place = dsu.get(wanted_place)
        print(real_place, end=' ')
        dsu.kill(real_place)
    print()
    return

if __name__ == '__main__':
    main()
