def is_prime(num):
    if num == 1:
        return False
    d = 2
    while d ** 2 <= num:
        if num % d == 0:
            return False
        d += 1
    return True

n = int(input())

dl = 10 ** 20
m = n
while m > 0:
    digits = list(map(int, str(m)))
    digits_sum = sum(digits)
    if is_prime(digits_sum):
        dl = abs(n - m)
        break
    m -= 1

dr = 10 ** 20
m = n
while True:
    digits = list(map(int, str(m)))
    digits_sum = sum(digits)
    if is_prime(digits_sum):
        dr = abs(n - m)
        break
    m += 1

ans = min(dl, dr)
print(ans)
