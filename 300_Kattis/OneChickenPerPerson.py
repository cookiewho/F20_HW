x, y = input().split()
z = abs(int(y) - int(x))
if int(y) < int(x):
  if z == 1:
    print("Dr. Chaz needs " + str(z) +" more piece of chicken!")
  else:
    print("Dr. Chaz needs " + str(z) +" more pieces of chicken!")
else:
  if z == 1:
    print("Dr. Chaz will have " + str(z) + " piece of chicken left over!")
  else:
    print("Dr. Chaz will have " + str(z) + " pieces of chicken left over!")