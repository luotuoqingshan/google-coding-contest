def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


T = int(input().strip())
for cas in range(T):
    n, l = map(int, input().strip().split())
    data = list(map(int, input().strip().split()))
    p = [0]*(l+1)
    for i in range(l - 1):
        c = gcd(data[i], data[i + 1])
        if c != data[i] and c != data[i + 1]:
            p[i + 1] = c
    for i in range(l):
        if p[i] != 0 and p[i + 1] == 0:
            p[i + 1] = data[i] // p[i]
    for i in range(l, 0, -1):
        if p[i] != 0 and p[i - 1] == 0:
            p[i - 1] = data[i - 1] // p[i]
    b = sorted(set(p)) 
    d = dict()
    for i in range(26):
        d[b[i]] = chr(ord('A') + i)
    string = ""
    for i in p:
        string += d[i]
    print("Case #" + str(cas+1) + ": " + string)
        


