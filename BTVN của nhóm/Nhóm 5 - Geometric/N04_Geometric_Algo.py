if __name__ == '__main__':
	points = list()
	for _ in range(3):
		x, y = map(float, input().split())
		points.append((x,y))

	val = (points[0][0] - points[1][0]) * (points[2][1] - points[1][1]) -\
			(points[2][0] - points[1][0]) * (points[0][1] - points[1][1])

	# print(val)

	if val > 0:
		print('Clockwise')
	if val == 0:
		print('Colinear')
	if val < 0:
		print('Couterclockwise')
