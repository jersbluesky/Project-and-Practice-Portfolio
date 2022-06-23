from pyrsistent import b


# Dictionaries and Keys
d = {'is_cat': True, 'name': "Mr. Fluffers", 'age_years': 7, 'weight_lbs': 192}

print(d['is_cat'])

print(d['name'])

print(d.get('age_years'))

# Key value pairs in tuples:
print(list(d.items()))

# binary representation

x = 255
print(f'{x:b}')

y = 0b1000101

print(y)

name = "Sandra"
age_years = 170

# Ternary operator
legal_status = "adult" if age_years >= 18 else "minor"

print(f'{name} is a {legal_status}.')

# Enumerate key word
my_list = ["apples", "pears", "oranges", "fruits"]

for x, element in enumerate(my_list):
    print(element)

# OUTPUT  
# apples
# pears
# oranges
# fruits

for x, element in enumerate(my_list):
    print(x, element)

# OUTPUT:
# 0 apples
# 1 pears
# 2 oranges
# 3 fruits
