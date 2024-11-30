def distance_sqr(x1: int, y1: int, x2: int, y2: int) -> int:
    return (x1 - x2) ** 2 + (y1 - y2) ** 2

def main() -> None:
    C = int(input())
    for _ in range(C):
        t1, x1, y1 = map(int, input().split())
        t2, x2, y2 = map(int, input().split())

        if t2 - t1 < 100:
            print(1)
        elif distance_sqr(x1, y1, x2, y2) <= 50 ** 2:
            if t2 - t1 <= 1000:
                print(2)
            else:
                print(3)
        else:
            print(4)
    
    return

if __name__ == '__main__':
    main()
