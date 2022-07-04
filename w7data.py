# Fibonacci Index - RECURSIVE
# Jeremy Johnson

# fib(-1) = 0
# fib(0) = 0
# fib(1) = fib(-1) + fib(0)
# fib(2) = fib(0) + fib(1) 
# fib(3) = fib(1) + fib(2)
# fib(4) = fib(2) + fib(3)
# fib(5) =

def fib(n):
    if n <= 1:
        fib_num = n
    else:
        fib_num = fib(n - 1) + fib(n - 2)
    return fib_num
        

def main():
    n = int(input("Enter a Fibonacci index: "))
    fib_number = fib(n)
    print(f'The Fibonnaci number is: {fib_number}')
    
if __name__ == "__main__":
    main()