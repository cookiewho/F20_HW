import sys
for i in sys.stdin:
  x, y = [int(num) for num in i.split()]
  if y == 0:
    continue
  else:
    r = x % y
    x = (x-r)//y
    print(x,r, '/' ,y)