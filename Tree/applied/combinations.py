import itertools

# list1 = ['a','b','c']
# list2 = [1, 2]

# list3 = [zip(x,list2) for x in itertools.permutations(list1, len(list2))]
# chain = itertools.chain(*list3)
# list4 = list(chain)
# print (list4)

# list5 = [1, 2, 3]
list5 = ['a','b','c']
list6 = [5, 6, 7, 8]
print (list(itertools.product(list5, list6)))