# This tool creates a List Array of random integers. The size, 
# minimum, and maximum integers are chosen by the user.

# Author: Jeremy Johnson
# Date: 7-17-2022


import numpy as np

class ListArray:
    def __init__(self):
        self._template_array = []
        
    def get_array_size(self):
        while True:
            try:
                self._array_size = int(input("Array size (must be positive): "))
                tryAgain = True
                while tryAgain == True:
                    if self._array_size < 0:
                        self._array_size = int(input("Try again. It must be a POSITIVE integer: "))
                        tryAgain = True   
                    else:
                        tryAgain = False 
                break
            except ValueError:
                print("Try again. It must be a positive INTEGER: ")
                continue    
        return self._array_size   

            
        return self._array_size
    
    def get_max_int(self):
        while True:
            try:
                self._max_int = int(input("Max integer: "))
                break
            except ValueError:
                print("It must be an INTEGER. Try again. ")
                continue  
        return self._max_int
    
    def get_min_int(self):
        while True:
            try:
                self._min_int = int(input("Min integer: "))
                break
            except ValueError: 
                print("It must be an INTEGER. Try again. ")
                continue
        return self._min_int
        
    def set_list_array(self):
        numpy_array = np.random.randint(self._min_int, self._max_int, self._array_size)
        self._template_array = list(numpy_array)

    def get_list_array(self):
        return self._template_array
    
    def execute(self): 
        array = ListArray()
        size = array.get_array_size()
        minInt = array.get_min_int()
        maxInt = array.get_max_int()
        list = array.set_list_array()
        return array.get_list_array()

# # TO CALL:
# createArray = ListArray()
# testList = createArray.execute()
# # To test:
# print(testList)