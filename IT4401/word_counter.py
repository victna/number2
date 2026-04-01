words = (input("Enter a string: ")).split() #takes input and splits it into a list of words
count = 0
for word in words: #iterates through the list of words
    if len(word)>4: #checks if the word contains only alphabetic characters
        count+=1 #increments the count if the word is valid
print(f"There are {count} words with more than 4 characters in the string.")