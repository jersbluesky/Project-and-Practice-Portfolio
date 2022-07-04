a_list = [12, 3, 5, 8, 90, 0]
b_list = [1, 2, 3, 4, 5, 6, 3, 2, 1, 1, 1]


def find_second_largest(list):
    largest = list[0]
    second_largest = None
    for i in range(len(list)):
        if list[i] > largest:
            second_largest = largest
            largest = list[i]
    return second_largest
        
find_second_largest(a_list)