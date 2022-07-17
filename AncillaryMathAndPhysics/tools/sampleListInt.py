# This tool creates a List Array of a sample size provided by the
# user. The size of the array is randomly set.

# Author: Jeremy Johnson
# Date: 7-17-2022

import numpy as np

class ListArray:
    def __init__(self):
        self._template_array = []
        
    def sample_size(self):
        self._sample_size = int(input("Sample Size: "))
        return self._sample_size
        
    def set_list_array(self):
        array_size = np.random.randint(0, self._sample_size)
        numpy_array = np.random.randint(0, self._sample_size, array_size)
        self._template_array = list(numpy_array)

    def get_list_array(self):
        return self._template_array
    
    def execute(self): 
        array = ListArray()
        size = array.sample_size()
        list = array.set_list_array()
        print(array.get_list_array())


# set1 = ListArray()
# set1.execute()
