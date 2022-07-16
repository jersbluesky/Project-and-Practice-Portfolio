# Simple Probability: written with objects
# Author: Jeremy Johnson
# Date: 7/16/2022

# If a number is randomly chosen from the following list, what is the
# probability that the number is a multiple of any given input?

import time
import numpy as np

from percent import Percent

class DivisibleBy:
    def __init__(self, prob_list_1, chosen_int) -> None:
            
        self._prob_list_1 = prob_list_1
        self._chosen_int = chosen_int
    
    def probability(self):
        nS = len(self._prob_list_1)
        nA = 0
        for i, value in enumerate(self._prob_list_1):
            if self._prob_list_1[i] % self._chosen_int == 0:
                nA += 1
        probability = Percent(nA / nS)
        print(probability)        
    
size = np.random.randint(5, 1000001)
print(size)
prob_list_1= np.random.randint(1,100000,size)

chosen_int = int(input("Choose and integer: "))

startTime = time.time()
testCaseOne = DivisibleBy(prob_list_1, chosen_int)
testCaseOneAnswer = testCaseOne.probability()

executionTime = (time.time() - startTime)
print('Execution time in seconds: ' + str(executionTime))   
            
        
