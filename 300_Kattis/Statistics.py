from sys import stdin
count = 0
for line in stdin:
  count+=1
  temp = [int(x) for x in line.strip().split()]
  temp.pop(0)
  mxN = max(temp)
  mnN = min(temp)
  print("Case " + str(count) + ":", mnN, mxN, mxN-mnN)