numbers = [3, 8, 12, 5, 7, 10]
evens = []
odds = []
print("Original list of numbers:", numbers)
for num in numbers:
    if num % 2 == 0: #checks if the number is even
        evens.append(num) #adds the number to the evens list
    else:
        odds.append(num) #adds the number to the odds list
print("Even numbers:", evens)
print("Odd numbers:", odds)