def clockwise(d1, d2):
    if (d1=='N' and d2=='E'):
        return True
    if (d1=='E' and d2=='S'):
        return True
    if (d1=='S' and d2=='W'):
        return True
    if (d1=='W' and d2=='N'):
        return True
    return False

n = int(input())
for i in range(n):
	turns = 0
	direct = input()
	prev = direct[0]
	#print(prev)
	i = 1
	for i in range(len(direct)):
		if direct[i] != prev:
			if (clockwise(prev, direct[i])):
				turns += 1
			else:
				turns -= 1
			prev = direct[i]
			#print(prev, " ", turns)
	if (turns > 0):
		print("CW")
	else:
		print("CCW")
