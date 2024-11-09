# Использую Python только из-за длинной арифметики
# Данное решение подходит и для первой версии задачи (задача 1009 из Timus-а)

def main() -> None:
    N, K = int(input()), int(input())

    zero = 0
    non_zero = 1
    for _ in range(N - 1):
        zero, non_zero = non_zero * (K - 1), zero + non_zero * (K - 1)
    
    answer = zero + non_zero * (K - 1)
    print(answer)

    return

if __name__ == '__main__':
    main()
