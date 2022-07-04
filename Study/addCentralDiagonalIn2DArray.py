# FUNCTION:

def diagonal_sum(given_2d):
    sum = 0
    for i in range(len(given_2d)):
        for j in range(len(given_2d[i])):
            if j == i:
                sum += given_2d[i][j]
        
    return sum

# TEST:

print("""
The diagonal sum of [[1, 2, 3, 1],
                     [4, 5, 6, 12],
                     [7, 8, 9, 10],
                     [4, 2, 1, 4]] is: (Should be 19)""")

answer = diagonal_sum([[1, 2, 3, 1],
              [4, 5, 6, 12],
              [7, 8, 9, 10],
              [4, 2, 1, 4]])

print(f'The answer is: {answer}.')