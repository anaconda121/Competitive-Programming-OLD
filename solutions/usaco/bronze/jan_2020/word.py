with open("word.in","r") as fin:
	L = list(fin)
	N,K = map(int,L[0].split())
	with open("word.out","w") as fout:
		w = 0 # current length of line
		for c in L[1].split(): # go through each word
			if w+len(c) > K: # place on new line
				fout.write("\n"+c)
				w = len(c)
			else: # place on current line
				if w > 0:
					fout.write(" ")
				fout.write(c)
				w += len(c)
		fout.write("\n")
