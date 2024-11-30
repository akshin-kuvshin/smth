def inverse(x: int) -> int:
    ans = 1
    while (x * ans) % 37 != 1:
        ans += 1
    return ans

def add(P: tuple[int, int], Q: tuple[int, int]) -> tuple[int, int]:
    if P == Q:
        alpha = (3 * P[0] ** 2 - 5) * inverse(2 * P[1])
    else: # P != Q
        alpha = (Q[1] - P[1]) * inverse(Q[0] - P[0])
    x = alpha ** 2 - P[0] - Q[0]
    y = alpha * (P[0] - x) - P[1]
    return (x % 37, y % 37)

def main() -> None:
    T = (6, 3)
    # Экспериментальным путём было получено, что приведённые в задании операции являются коммутативными и ассоциативными.
    for _ in range(12):
        T = add(T, (6, 3))
    print(T)
    return

if __name__ == '__main__':
    main()
