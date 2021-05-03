def brute(L, n):
    if len(L) == 2:
        return L[0] == L[1]
    for i in range(len(L)-1):
        xor = L[i] ^ L[i+1]
        new_L = L[0:i] + [xor] + L[i+2:]
        if brute(new_L, len(L)):
            return True


def solve():
    n = int(input())
    arr = [int(x) for x in input().split()]
    if brute(arr, n):
        print("YES")
    else:
        print("NO")


def main():
    t = int(input())
    while t:
        t -= 1
        solve()


if __name__ == '__main__':
    main()
