inp = [int(x) for x in input().split()]
max_n = 0
for y in range(len(inp)-1):
  diff = inp[y+1] - inp[y]
  if max_n < diff:
    max_n = diff
print(max_n-1)