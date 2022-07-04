# Shopping List 
# Author: Jeremy Johnson
# 10/30/2021

# "WILD WILLY'S EVERYTHING SHOP" Shopping Cart App


# lists needed: 
# cart
# cost

# functions required:
# select an option
# add item
# add cost
# view list of items
# view total cost
# remove items
# quit

# parameters:
# re-post options after each selection
# quit upon quitting

# Step 1: Create the lists and import programs

cart = []
cost = []


import textwrap
import sys



# Step 2: present the options, prompt the selection, and call the loop:

# Welcome to Wild Willy's Everything Store, where you can choose any item your heart desires, and set your own dadgum price!
# Please select one of the following:
# 1. Add item
# 2. View cart
# 3. Remove item
# 4. Compute total
# 5. Quit

print()
intro = "Welcome to Wild Willy's Everything Store, where you can choose any item your heart desires, and set your own dadgum price!"
intro_wrap = '\n'.join(textwrap.wrap(intro, 80, break_long_words=False))


# Main menu shows menu items, allows the user to select an option, and calls a function based on the selection
def mainMenu ():
    while True:
        print()
        def menu():
            print("Please select one of the following: ")
            print("1. Add item")
            print("2. View cart")
            print("3. Remove item")
            print("4. Compute total")
            print("5. Quit")

        menu()
        option = input("Please enter and action: ")

        if option == "1":
            addItem()
        elif option == "2":
            viewCart()
        elif option == "3":
            removeItem()
        elif option == "4":
            viewCost()
        elif option == "5":
            sys.exit()
        else:
            print("You didn't make a valid selection. Try again. ")


# 1 Add an item: This adds the input to the lists. A lot of freedom given to the cashier here...
def addItem():
    item = input("What item would you like to add? ")
    price = float(input(f"what is the price of {item}? "))
    price2f = "{0:,.2f}".format(price)
    cost.append(float(price))
    cart.append(item + " $" + str(price2f))
    print(f"{item} has been added to your cart!")

# 2 View cart iterates through the cart and prints the items therein
def viewCart():
    print()
    print("Cart")
    for count, i in enumerate(cart,1): 
        print(count, i)

# 3 This pops the item associated with the list number off the list.
def removeItem():
    item = input("What item would you like to remove? ")
    cart.pop(len(item) - 1)
    cost.pop(len(item) - 1)
    print("Item has been removed from your cart!")


# 4 This shows the cost.
def viewCost():
    total = sum(cost)
    total2f = "{0:,.2f}".format(total)
    print(f"${total2f}")


print(intro_wrap)
mainMenu()

