s1 = input()
chars = {}
for x in s1:
  if x in chars:
    chars[x] += 1
  else:
    chars[x] = 1
odd = 0
for num in chars.values():
  if num %2 != 0:
    odd+=1
ans = odd -1
if (ans < 0):
  ans = 0
print(ans)