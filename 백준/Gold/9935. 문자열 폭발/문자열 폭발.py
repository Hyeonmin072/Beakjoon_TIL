st = input()
keyword = input()

s = []
k = len(keyword)

for i in range(len(st)):
    s.append(st[i])

    if len(s) >= k:
        stack_end = "".join(s[-k:])
        if stack_end == keyword:
            for _ in range(k):
                s.pop()

if len(s) == 0:
    print("FRULA")
else:
    print("".join(s))
