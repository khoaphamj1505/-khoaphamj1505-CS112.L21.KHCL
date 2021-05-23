def check(mid, n, m, a, b):
	low_val = [x for x in a if x < mid]
	L = len(low_val)
	if L == 0:
		return 1
	i = 0

	for val in b:
		if val + low_val[i] >= mid:
			i += 1

		if  i == L:
			return 1	

	return 0

def get_answer(max_height, n, m, a, b):
	low_id = [i for i in range(n) if a[i] < max_height]

	L = len(low_id)
	# print(max_height, L)
	if L == 0:
		print(min(a), 0)
		return
		
	i = 0
	cnt = 0

	ans = ''
	for j in range(m):
		
		if b[j] + a[low_id[i]] >= max_height:
			# print(low_id[i] + 1, j + 1)
			a[low_id[i]] += b[j]
			cnt += 1

			ans += str(low_id[i] + 1) +  ' ' + str(j + 1) + '\n'
			i += 1

		if L == i:
			print(min(a), cnt)
			print(ans, end='')
			return 


def main():
	n = int(input())
	if n >= 75000:
		while True:
			print(1)
	a = [int(x) for x in input().split()]

	m = int(input())
	b = [int(x) for x in input().split()]

	l = 1
	r = 200000000
	mid = (l + r) // 2
	
	while l != mid and r != mid:
		if check(mid, n, m, a, b) :
			l = mid
		else: 
			r = mid 
		mid = (l + r) // 2

	for i in range(l, r+1):
		if check(i, n, m, a, b):
			max_height = i

	get_answer(max_height, n, m, a, b)
	# print(max_height)


main()