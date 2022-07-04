# Simple Restaurant calculator
# Date - 9/9/2021
# AUTHOR: Jeremy Johnson
#
# Take the input from the user on the cost of an adult and child meal, then how many adults and children are dining,
# then the tax rate. It returns the subtotal, the sales tax, and then the amount due. 
#
# It then prompts the user for a tip amount. The total is re-calculated, and the user is prompted for an amount
# given by the customer. The return amount is the calculated change for the user.

# Title is optional, but we made it. Go us.
print("________------****-----****C***H***U***C***K***-***O***-***M***A***N***I***A***-----****-------________")
print("--------------------------------------------------------------------------------------------------------")
print("------------------------------------------GOURMET--------BUFFET-----------------------------------------")
print("--------------------------------------------------------------------------------------------------------")
print()

# We put this in a loop to continue the code until the user enters 'n' when prompted if they
# want to run again.
while True:
    # Inputs. 'Nuff said.
    child = float(input("What is the price of a child's meal? "))
    adult = float(input("What is the price of an adult's meal? "))
    childnum = int(input("How many children are there? "))
    adultnum = int(input("How many adults are there? "))
    tax = float(input("What is the sales tax rate? " ))

    # Sub total, tax total, and total amount are all parsed as floats.
    subtotal = float(child * childnum + adult * adultnum)
    taxtotal = float(subtotal * tax / 100)

    totalamount = float(subtotal + taxtotal)

    print()
    # The amount is limited to 2 decimals and placed in informatory strings.
    print("Subtotal: $" + str(format(subtotal, ",.2f")))
    print("Sales Tax: $" + str(format(taxtotal, ",.2f")))
    print("The total amount due is: $" + str(format(totalamount, ",.2f")))

    print()

    # Ask for a tip and put it in the tip variable.
    tip = float(input("How much do you value me as a person, monetarily?(how much will the tip be?) "))

    print()

    # Output if/else. If no tip, guilt trip time.
    if tip == 0:
        print("Well, that makes me feel bad, and hopefully will make you feel guilty. One thing's for sure, though. The rest of this transaction is going to be super awkard.")
    else:
        print("Thanks for being a good person.")

    print()

    # New total with tip.
    print("The total amount is going to be $" + str(format(totalamount + tip, ",.2f")))

    payment = (float(input("What is the payment amount? ")))

    print("Change: $" + str(format(payment - (totalamount + tip), ",.2f")))

    answer = str(input('Run again? (y/n): '))

    if answer == "n" or "no":
        print("Goodbye")
        break
    elif answer == "y" or "yes":
        print()
        continue
    else:
        print("Umm, that wasn't a y or n. I guess we'll just run it again. Pull yourself together.")