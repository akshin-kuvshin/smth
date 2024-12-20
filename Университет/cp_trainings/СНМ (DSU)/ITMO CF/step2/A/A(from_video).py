# THIS PROGRAM GETS "RUNTIME ERROR" ON TEST #15

class DSU(object):
    def __init__(self, n: int) -> None:
        self.__n = n
        self.p = list(range(self.__n + 5))
        return
    
    # works ~ for O(logn)
    def __get(self, a: int) -> int:
        if self.p[a] != a:
            self.p[a] = self.__get(self.p[a])
        return self.p[a]
    
    def kill(self, a: int) -> None:
        self.p[a] = a + 1
        return
    
    def get_right(self, a: int) -> int:
        right = self.__get(a)
        return right if right <= self.__n else -1

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
