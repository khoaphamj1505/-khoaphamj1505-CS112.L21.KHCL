from math import gcd

if __name__ == '__main__':
	a = int(input())
	b = int(input())
	c = int(input())
	d = int(input())
	cnt = 0

	if a * d > b * c:
		print(0)
	else:
		while a * d < b * c:	
			cnt += 1
			a = a + 1
			b = b + 1

			_gcd = gcd(a, b)
			a //= _gcd
			b //= _gcd

		if a * d != b * c:
			print(0)
		else:
			print(cnt)
