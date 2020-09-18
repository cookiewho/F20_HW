size = int(input())
sets = [x for x in input().split()]

for x in range(0, pow(2, size)):
  bitNum = ""
  bitString = ""
  on = False
  for y in range(0, size):
    if (x & (1<<y)):
      bitNum = "1" + bitNum
      print(size-y)
      bitString += str(sets[(size-y)-1]) + " "
      on = True
    else:
      bitNum = "0" + bitNum
  if on:
    print(bitNum + ":" + bitString)
  else:
    print(bitNum + ":EMPTY")
