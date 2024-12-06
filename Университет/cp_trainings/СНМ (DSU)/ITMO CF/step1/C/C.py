class DSU(object):
    def __init__(self, n: int) -> None:
        self.p = [i for i in range(n + 1)]
        self.size = [1] * (n + 1)
        self.e = [0] * (n + 1)
        return
    
    def __get(self, a: int) -> tuple[int, int]:
        if a == self.p[a]:
            return (a, 0)
        
        res = self.__get(self.p[a])
        self.p[a] = res[0]
        self.e[a] += res[1]
        return (self.p[a], self.e[a])
    
    def union(self, a: int, b: int) -> None:
        a = self.__get(a)[0]
        b = self.__get(b)[0]
        if a == b:
            return
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.p[b] = a
        self.size[a] += self.size[b]
        self.e[b] -= self.e[a]
        return
    
    def add_exp(self, a: int, val: int) -> None:
        a = self.__get(a)[0]
        self.e[a] += val
        return
    
    def get_exp(self, a: int) -> int:
        p = self.__get(a)[0]
        if a == p:
            return self.e[a]
        return self.e[a] + self.e[p]

def main() -> None:
    n, m = map(int, input().split())
    dsu = DSU(n)
    for _ in range(m):
        inputs = input().split()
        if inputs[0] == 'join':
            x, y = int(inputs[1]), int(inputs[2])
            dsu.union(x, y)
        elif inputs[0] == 'add':
            x, v = int(inputs[1]), int(inputs[2])
            dsu.add_exp(x, v)
        else: # inputs[0] == 'get'
            x = int(inputs[1])
            print(dsu.get_exp(x))
    return

if __name__ == '__main__':
    main()
