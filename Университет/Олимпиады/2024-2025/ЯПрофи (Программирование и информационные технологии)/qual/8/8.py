def b_weight(x: int, b: int) -> int:
    weight = 0
    while x:
        weight += (x % b) ** 2
        x //= b
    return weight

def main() -> None:
    n, b = map(int, input().split())
    a = list(map(int, input().split()))
    weights = list(map(b_weight, a, [b] * n))
    a = list(zip(a, weights))
    a.sort(key=lambda x: x[1])
    for p in a:
        print(p[0], end=' ')
    print()
    return

if __name__ == '__main__':
    main()
