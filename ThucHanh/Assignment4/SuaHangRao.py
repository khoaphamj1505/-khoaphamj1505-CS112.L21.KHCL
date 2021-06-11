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
	low_id = [(a[i], i) for i in range(n) if a[i] < max_height]

	L = len(low_id)
	print(max_height, L)
	if L == 0:
		return
	i = 0
	j = 0

	val, index = low_id[i]

	ans = ''
	for j in range(m):
		
		if val + b[j] >= max_height:
			# print(low_id[i] + 1, j + 1)
			ans += str(index+ 1) +  ' ' + str(j + 1) + '\n'
			i += 1

		if L == i:
			print(ans, end='')
			return 
		val, index = low_id[i]
		
def main():
	n = int(input())
	a = [int(x) for x in input().split()]

	m = int(input())
	b = [int(x) for x in input().split()]

	l = 1
	r = 2* (10**8) + 1

	while l < r :
		mid = (l + r) // 2
		if check(mid, n, m, a, b) :
			l = mid + 1
		else: 
			r = mid 

	max_height = l - 1
	get_answer(max_height, n, m, a, b)


main()