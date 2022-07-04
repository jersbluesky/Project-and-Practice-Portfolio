# Simple data and array practice - add to arrays
# Week 3

# Get input from the user, put those numbers in an array based on if it is even or odd,
# then print out the arrays when the user quits.

odds = []
evens = []

option = 1
while option != 0:
    option = int(input("Enter a number (0 to quit): "))
    if option % 2 != 0:
        odds.append(option)
    elif option % 2 == 0:
        evens.append(option)

print("\nEven numbers: ")
for number in evens:
    print(number)

print("\nOdd numbers: ")
for number in odds:
    print(number)
    
    

