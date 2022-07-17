# INTERSECTION SOLUTION REVERSE-ENGINEERING

# This is a solution I reverse-engineered from a YouTube solution
# provided on based on a Leetcode challenge. I was teaching myself
# intersections, and wanted to complete a challenge that involved
# intersections. 

# In the process, I also completed a complete run-down of all of
# the uses of the Count module.

# The print statements that are commented out were my way of 
# understanding why the code from the YouTube user works.

import time
import sys
from typing import Counter
sys.path.insert(0, 'c:/Users/Predator/Desktop/Applied Technology/Practiceandproblems/practiceandproblems/')
import numpy as np 
from AncillaryMathAndPhysics.tools.sampleListInt import ListArray

    
class Intersections:
    def __init__(self, list1, list2):
        self._list1 = list1
        self._list2 = list2
        
    def determine_intersections(self):
        count = Counter(self._list1)
        output = []
        # roundCount = 1
        # print(count)
        for n in self._list2:
            # print(f'ROUND {roundCount}')
            # print(f'n = {n}')
            # print(f'countn = {count[n]}')
            if count[n] > 0:
                output.append(n)
                # print(f'output = {output}')
                # print(count[n])
                count[n] -= 1
                # print(count[n])
                # print(count)
            # roundCount += 1
        # print(output)
        return output
        
        
getList = ListArray()
print("List 1 parameters: ")
list1 = getList.execute()
print("List 2 parameters: ")
list2 = getList.execute()

print(f'List 1: {list1}')
print(f'List 2: {list2}')

startTime = time.time()
intersections = Intersections(list1, list2)
output = intersections.determine_intersections()
print(output)
executionTime = (time.time() - startTime)
print(executionTime)