# Circle Circumference Probability Problem
# Question taken directly from a probability problem in
# Khan Academy

# Author: Jeremy Johnson
# Date: 7/16/2022


# The circumference of a circle is 36 * pi. Contained in that
# circle is a smaller circle with an area of 16 * pi. A point is
# selected at random from inside the larger circle. What is the
# probability that the point also lies in the smaller circle?

# Will adjust to randomly import the circumference of the circle
# and the area of the smaller circle (which must be smaller).

from percent import Percent as per
import numpy as np
import time

class CircleProbability:
    def __init__(self, large_circle_area, small_circle_area):
        self._large_circle_area = large_circle_area
        self._small_circle_area = small_circle_area
    
    def probability(self):
        print(f' The small circle has an area of: {self._small_circle_area}, and the large on has an area of {self._large_circle_area}.')
        print(per(self._small_circle_area / self._large_circle_area))

large_circle_circ = np.random.randint(5, 1000)
large_circle_area = int((large_circle_circ/2) ** 2)
small_circle_area = np.random.randint(0, large_circle_area)

startTime = time.time()
testCaseOne = CircleProbability(large_circle_area, small_circle_area)
testCaseOneAnswer = testCaseOne.probability()

# Test from the Khan Academy problem:
large_circle_circ2 = 36
large_circle_area2 = int((large_circle_circ2/2) ** 2)
small_circle_area2 = 16
testCase2 = CircleProbability(large_circle_area2, small_circle_area2)
testCase2Answer = testCase2.probability()

executionTime = (time.time() - startTime)
print('Execution time in seconds: ' + str(executionTime))   
        
        
