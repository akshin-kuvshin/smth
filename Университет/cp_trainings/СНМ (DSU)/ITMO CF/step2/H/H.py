import operator as op

# Code was taken from my solution of problem E in this step.

class DSU(object):
    def __init__(self, n: int) -> None:
        self.p = list(range(n))
        self.size = [1] * n
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
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.p[b] = a
        self.size[a] += self.size[b]
        return

def main() -> None:
    n, m, s = map(int, input().split())
    ribs = []
    full_sum = 0
    for i in range(m):
        u, v, cost = map(int, input().split())
        ribs.append({
            'u': u - 1,
            'v': v - 1,
            'cost': cost,
            'ind': i + 1,
            'used': False
        })
        full_sum += cost
    ribs.sort(key=op.itemgetter('cost'), reverse=True)

    dsu = DSU(n)
    cur_sum = cnt = 0
    for i in range(m):
        if cnt == n - 1:
            break
        if dsu.get(ribs[i]['u']) == dsu.get(ribs[i]['v']):
            continue
        dsu.unite(ribs[i]['u'], ribs[i]['v'])
        cur_sum += ribs[i]['cost']
        ribs[i]['used'] = True
        cnt += 1
    
    for i in range(m):
        if cur_sum >= full_sum - s:
            break
        if ribs[i]['used']:
            continue
        cur_sum += ribs[i]['cost']
        ribs[i]['used'] = True
        cnt += 1
    
    ribs.sort(key=op.itemgetter('ind'))
    k = m - cnt
    print(k)
    for i in range(m):
        if not ribs[i]['used']:
            print(ribs[i]['ind'], end=' ')
    print()

    return

if __name__ == '__main__':
    main()
