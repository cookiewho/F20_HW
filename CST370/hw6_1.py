from collections import OrderedDict
vs = int(input())
graph = [[]] *vs
cities_ind = {}
ind_cities = {}
ans = OrderedDict()
for x in range(vs):
  temp = input()
  cities_ind[temp] = x
  ind_cities[x] = temp


edges = int(input())
for x in range(edges):
  temp = [y for y in input().split()]
  graph[cities_ind[temp[0]]].append(cities_ind[temp[1]])


curr = cities_ind[input()]
hops_allowed = int(input())
visited= [0]*len(graph)
visited[curr] = 1
hops_taken = 0
if hops_allowed >0:
  ans[ind_cities[curr]] = 0


q = [curr]
while(len(q) > 0):
  curr = q.pop(0)
  for x in range(len(graph[curr])):
    neighbor = graph[curr][x]
    if visited[neighbor] == 0:
      visited[neighbor]=1
      q.append(neighbor)
      # print("prev", ans[ind_cities[curr]])
      hops_taken = ans[ind_cities[curr]]+1
      if hops_taken<=hops_allowed:
        ans[ind_cities[neighbor]] = hops_taken
print()
for key in sorted(ans.keys()):
  print(key, ans[key])
