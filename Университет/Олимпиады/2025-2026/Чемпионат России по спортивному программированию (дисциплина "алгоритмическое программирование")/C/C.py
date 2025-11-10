# author: Danila "akshin_" Axyonov

def main() -> None:
    a, b = map(int, input().split())

    l, r = 0, 1_000_000_000
    while l + 1 < r:
        x = (l + r) // 2
        xxx = int(str(x) + str(x ** 2))
        if xxx >= a:
            r = x
        else: # xxx < a
            l = x
    x1 = r

    l, r = 0, 1_000_000_000
    while l + 1 < r:
        x = (l + r) // 2
        xxx = int(str(x) + str(x ** 2))
        if xxx > b:
            r = x
        else: # xxx <= b
            l = x
    x2 = r

    print(x2 - x1)

q = int(input())
for _ in range(q):
    main()
