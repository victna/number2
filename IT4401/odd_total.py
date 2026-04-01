running = True
while running:
    input_str = input("Enter a sequence of numbers (comma separated) or Done (case sensitive) to quit:")
    if input_str == "Done":
        running = False
        continue
    items = input_str.split(",") #splits input into a list of items based on commas
    total = 0 
    indice = 0
    for item in items:
        indice += 1
        item = item.strip() #removes leading and trailing whitespace
        if item == "Done": #checks if the user wants to quit
            running = False
            break
        try:
            num = float(item) #converts the item to a float
            if indice % 2 != 0: #checks if the index is odd
                total += num #adds the number to the total
        except ValueError:
            print(f"Invalid input '{item}'. Please enter a valid number or 'Done' to quit.")
    print(f"The sum of numbers at odd indices is {total}")
print("Goodbye!")