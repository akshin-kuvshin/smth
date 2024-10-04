n = int(input())
stack_a = [int(x) for x in input().split()]
stack_b = []
to_release = 1
count = 0
clear_a = False
clear_b = False

while to_release <= n:
    if stack_a and stack_a[-1] == to_release:
        stack_a.pop()
        to_release += 1
        count += 1
    elif stack_b and stack_b[-1] == to_release:
        stack_b.pop()
        to_release += 1
        count += 1
    else:
        if stack_a and clear_a:
            stack_b.append(stack_a.pop())
            count += 1
            continue
        elif stack_b and clear_b:
            stack_a.append(stack_b.pop())
            count += 1
            continue

        if stack_a:
            clear_a = True
            clear_b = False
        elif stack_b:
            clear_b = True
            clear_a = False

print(count)
