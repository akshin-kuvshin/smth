ans = 0

n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

dA = {}
dB = {}
for num in A:
    dA[num] = dA.get(num, 0) + 1
for num in B:
    dB[num] = dB.get(num, 0) + 1

lA = sorted([{'num': _num, 'amount': _amount} for _num, _amount in dA.items()], key=lambda x: x['num'], reverse=True)
lB = sorted([{'num': _num, 'amount': _amount} for _num, _amount in dB.items()], key=lambda x: x['num'])

diff = lB[-1]['num'] - lA[-1]['num']
while diff > 0:
    if lA[-1]['amount'] <= lB[-1]['amount']:
        tmp = lA.pop()
        _num, _amount = tmp['num'], tmp['amount']

        if len(lA) == 0:
            ans += diff * _amount
            break

        d = min(diff, lA[-1]['num'] - _num)
        diff -= d
        ans += d * _amount

        _num += d
        lA[-1]['amount'] += _amount
    else: # lA[-1]['amount'] > lB[-1]['amount']
        tmp = lB.pop()
        _num, _amount = tmp['num'], tmp['amount']

        if len(lB) == 0:
            ans += diff * _amount
            break

        d = min(diff, _num - lB[-1]['num'])
        diff -= d
        ans += d * _amount

        _num -= d
        lB[-1]['amount'] += _amount

print(ans)
