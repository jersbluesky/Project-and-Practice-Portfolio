import sys
sys.path.insert(0, 'c:/Users/Predator/Desktop/Applied Technology/Practiceandproblems/practiceandproblems/')
from collections import Counter
from AncillaryMathAndPhysics.tools.sampleListInt import ListArray
# The 'ListArray' class is a tool that creates a List Array of a 
# sample size provided by the user. The size of the array is 
# randomly set. It could populate an empty array, and can output
# duplicate integers.
print("List 1: ")
setlist1 = ListArray()
list1 = setlist1.execute()
print("List 2: ")
setlist2 = ListArray()
list2 = setlist2.execute()
print(f'List 1: {list1}')
print(f'List 2: {list2}')

count1 = Counter(list1)
count2 = Counter(list2) 
print(count1, count2)

# specificCount = count[4]
# print(specificCount)

# count[3] = 20
# print(count[3])
# print(count)
# print(list1)

# del count[3]
# print(count)

# x = list(count.elements())
# print(x)

# y = count.most_common(5)
# print(y[0][0])

z = count1 + count2
print(z)