numbers = [12, 18, 128, 48, 2348, 21, 18, 3, 2, 42, 96, 11, 42, 12, 18]

numbers.insert(0, 5)
print(numbers)

for i in numbers:
    if i == 2348:
        numbers.remove(i)

print(numbers)

numbers_2 = [1,2,3,4,5]

numbers.extend(numbers_2)

print(numbers)

numbers.sort()

print(numbers)

numbers.reverse()

print(numbers)

print(numbers.count(12))

print(numbers.index(96))

slice_1 = int(len(numbers)/2)-1
slice_2 = -(slice_1)
print(slice_1)
print(slice_2)

print(numbers[:slice_1])
print(numbers[slice_2:])

