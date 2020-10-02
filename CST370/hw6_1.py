from collections import OrderedDict
vs = int(input())
graph = [[]] *vs
print (graph)
cities_ind = {}
ind_cities = {}
ans = OrderedDict()
for x in range(vs):
  temp = input()
  cities_ind[temp] = x
  ind_cities[x] = temp
print(cities_ind)
edges = int(input())
for x in range(edges):
  temp = [y for y in input().split()]
  graph[cities_ind[temp[0]]].append(cities_ind[temp[1]])
curr = cities_ind[input()]
hops_allowed = int(input())
visited = [curr]
hops_taken = 0
q = [curr]
while((len(q) > 0) and hops_taken <= hops_allowed):
  curr = q.pop()
  ans[ind_cities[curr]] = hops_taken
  for x in range(len(graph[curr])):
    neighbor = graph[curr][x]
    if neighbor in visited:
      print(neighbor, "already here")
    else:
      visited.append(neighbor)
      q.append(neighbor)
  print("APPENDED", q)
  print("VISITED", visited)
  hops_taken+=1
for key,val in ans.items():
  print(key, val)
