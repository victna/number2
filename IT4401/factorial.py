import math
validInput = False
for i in range(100): #for loop allows 100 attempts (not super necesary but it is a good practice to limit attempts)
    try:
        n = int(input("Enter a non-negative integer: "))
        if n < 0: #checks if input is negative
            print("Please enter a non-negative integer.")
            i -= 1 #decrements the loop counter to allow for another attempt without counting it as an attempt (unlimited attempts)
        else:
            validInput = True #sets validInput to true to break out of the loop
            break
    except ValueError:
        print("Invalid input. Please enter a non-negative integer.")
factorial = math.factorial(n) #uses math module to calculate factorial of n
print(f"The factorial of {n} is {factorial}")