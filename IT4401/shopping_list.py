shopping_list = [] #creates an empty list to store the shopping items
while True: #starts an infinite loop to continuously ask for input
    item = input("Enter an item to add to the shopping list (or type 'done' to finish): ") #asks the user for an item
    if item.lower() == 'done': #checks if the user wants to finish adding items
        break #exits the loop if the user is done
    shopping_list.append(item) #adds the item to the shopping list
print("Your shopping list:") #prints the shopping list
for item in shopping_list: #iterates through the shopping list and prints each item with its index
    print(f"{item} ") #prints the index and the item