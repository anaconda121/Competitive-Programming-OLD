import sys
sys.stdin = open("cbarn.in", "r") #redirecting input/output
sys.stdout = open("cbarn.out", "w")

n = int(input())
roomCows = []
for i in range(n):
	roomCows.append(int(input()))

moves = []
for i in range(n): #iterate through every possible door
	move = 0
	for offset in range(n): #count how many cows have to walk a distance of "offset"
		move += offset * roomCows[(i+offset)%n];
	moves.append(move)
print(min(moves))
