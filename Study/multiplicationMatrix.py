# Multiplication Matrix
# Author: Jeremy Johnson
# 10/3/2021

num = int(input("How many columns and rows do you want on your multiplication table? "))
size = num + 1
for row_num in range(1, size):
    for col_num in range(1, size):
        total = row_num * col_num
        print(f"{total}", end=" ")
    print()
user_choice = int(input("How many columns and rows do you want in your multiplication table? "))

# When we use range() in the loop below, it will go up to, but NOT INCLUDING the number
# so here we set the range_size to be the user's choice plus one.
range_size = user_choice + 1

# Iterate through that number of rows
for row_number in range(1, range_size):
    # For each for, we will also iterate through the same number of columns
    for col_number in range(1, range_size):
        # The number to display is the product of the row_number and the col_number
        number = row_number * col_number
        # Display the number with a space instead of a newline at the end: `end=" "`
        print(f"{number}", end=" ")
    
    # We have now printed all of the columns and are done with the row.
    # So it is now time to start a new line.
    print()