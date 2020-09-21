size = int(input())
vals = []
ins = 0
while ins < size:
  vals.append(int(input()))
  ins+=1
print(vals)

max_string = ""
max_num = 0
for x in range(0, pow(2, size)):
  bitNum = ""
  bitString = ""
  next_to = False
  valid = True
  temp_total = 0
  for y in range(0, size):
    if (x & (1<<y)):
      if (next_to):
        valid = False
        break;
      bitNum = "1" + bitNum
      bitString += str(y) + " ";
      temp_total += vals[y]
      next_to = True
    else:
      bitNum = "0" + bitNum
      next_to = False
  if valid:
    if temp_total > max_num:
      max_num = temp_total
      max_string = bitString
print("Boxes:"+max_string)
print("Max Apples:" + str(max_num))
'''
  if for x in range(0, size):

  if on:
    print(bitNum + ":" + bitString)
  else:
    print(bitNum + ":EMPTY")
    '''