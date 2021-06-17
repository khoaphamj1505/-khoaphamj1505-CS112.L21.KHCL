#CS112.L21.KHCL 
#Nhóm 4

from collections import deque

dx = [-1, 0, 0, 1]
dy = [0, 1, -1, 0]
grid = list()

def valid(x, y, n, m):
	if x >= 0 and  y >= 0 and x < n and y < m:
		return 1
	return 0

def bfs(x_start, y_start, x_end, y_end):

	check_grid = [[-1 for _ in range(m)] for i in range(n)]
	check_grid[x_start][y_start] = 0

	Q = deque()
	Q.append((x_start, y_start)	)

	while len(Q) :
		x, y = Q.popleft()
		if x == x_end and y == y_end:
			break

		for addx, addy in zip(dx, dy):
			x_new = x + addx
			y_new = y + addy

			if valid(x_new, y_new, n, m) and \
					check_grid[x_new][y_new] == -1\
					and grid[x_new][y_new] != '#':

				Q.append((x_new, y_new))
				check_grid[x_new][y_new] = check_grid[x][y] + 1

	print(check_grid[x_end][y_end])

if __name__ == '__main__':
	n, m = map(int, input().split())	
	grid = [list(input()) for _ in range(n)]

	x_start, y_start = -1, -1
	x_end , y_end = -1, -1

	for i in range(n):
		for j in range(m):
			if grid[i][j] == 's':
				x_start , y_start = i, j 
			if grid[i][j] == 'e':
				x_end, y_end = i, j

	bfs(x_start, y_start, x_end, y_end)
