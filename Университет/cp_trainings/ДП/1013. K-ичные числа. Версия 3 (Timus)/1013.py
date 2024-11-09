def mat_prod(A: tuple, B: tuple, MOD: int) -> tuple:
    return (
        ((A[0] * B[0]) % MOD + (A[1] * B[2]) % MOD) % MOD,    ((A[0] * B[1]) % MOD + (A[1] * B[3]) % MOD) % MOD,
        ((A[2] * B[0]) % MOD + (A[3] * B[2]) % MOD) % MOD,    ((A[2] * B[1]) % MOD + (A[3] * B[3]) % MOD) % MOD
    )

def mat_pow(A: tuple, ptr: int, MOD: int) -> tuple:
    if ptr == 1:
        return A
    half_ptr: int = ptr // 2
    half_res: tuple = mat_pow(A, half_ptr, MOD)
    almost_res: tuple = mat_prod(half_res, half_res, MOD)
    if ptr % 2 == 0:
        return almost_res # ptr is even number
    return mat_prod(almost_res, A, MOD) # ptr is odd number

def main() -> None:
    N: int = int(input())
    K: int = int(input())
    MOD: int = int(input())
    a1: int = 0
    a2: int = (K - 1) % MOD

    # truly, a[n] is f(n, 0),
    # and f(n, 1) we can find as f(n, 0) + f(n - 1, 0) = a[n] + a[n - 1]
    
    if N == 2:
        answer: int = (a2 + (((a2 + a1) % MOD) * ((K - 1) % MOD)) % MOD) % MOD
        print(answer)
        return
    
    M: tuple = mat_pow(
        (0, 1, (K - 1) % MOD, (K - 1) % MOD),
        N - 2,
        MOD
    )
    
    an_1: int = ((a1 * M[0]) % MOD + (a2 * M[1]) % MOD) % MOD
    an: int = ((a1 * M[2]) % MOD + (a2 * M[3]) % MOD) % MOD
    answer: int = (an + (((an + an_1) % MOD) * ((K - 1) % MOD)) % MOD) % MOD
    print(answer)
    return

if __name__ == '__main__':
    main()
