def main(n, m, t):
	print("RFP #", t, sep='')

	mp = dict()

	for _ in range(n):
		s = input()
		mp[s] = 1

	final_name = " "
	min_val = float('inf')
	count_max = -1

	for _ in range(m):
		name = input()

		money, c = map(float, input().split())
		c = int(c)
		cnt = 0

		while c > 0 :
			c -= 1
			s = input()
			cnt += mp[s]

		# print(name, money, cnt)
		if cnt > count_max or (cnt == count_max and min_val > money):
			count_max = cnt;
			min_val = money
			final_name = name

	print(final_name)
	print()

if __name__ == '__main__':
	t = 1
	while True:
		n, m = map(int, input().split())
		if n == 0 and m == 0:
			break
		else:
			main(n, m, t)
			t += 1	