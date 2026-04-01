alphabet = {"a": 0, "b": 1, "c": 2, "d": 3, "e": 4, "f": 5, "g": 6, "h": 7, "i": 8, "j": 9,
            "k": 10, "l": 11, "m": 12, "n": 13, "o": 14, "p": 15, "q": 16, "r": 17, "s": 18, "t": 19, "u": 20,
            "v": 21, "w": 22, "x": 23, "y": 24, "z": 25}  #Create a mapping of letters to their corresponding indices
def encrypt(s, n):
    cipher_text = ""  #string for holding the encrypted text
    for char in s:
        if char.isalpha(): #checks if the character is an alphabet letter, if not does nothing
            char = char.lower()
            index = (alphabet[char] + n) #finds the shifted index by adding N to the original index
            index = index % 26 #wraps around the alphabet
            cipher_char = list(alphabet.keys())[list(alphabet.values()).index(index)] #calculates the correct letter 
            cipher_text += cipher_char #adds the encrypted character
        else:
            cipher_text += char #adds non-alphabetic character
    return cipher_text  #returns the encrypted string
def decrypt(s, n):
    shifted_text = ""  #string for holding the decrypted text
    for char in s:
        if char.isalpha():
            char = char.lower()
            index = (alphabet[char] - n) #finds the shifted index by subtracting N from the original index
            index = index % 26 #wraps around the alphabet
            shifted_char = list(alphabet.keys())[list(alphabet.values()).index(index)] #calculates the correct letter 
            shifted_text += shifted_char #adds the decrypted character
        else:
            shifted_text += char #adds non-alphabetic character
    return shifted_text  #returns the decrypted string
def main():
    choice = input("Enter 'e' to encrypt or 'd' to decrypt: ").lower()
    while choice != "done": #runs until user quits
        if choice in ["e", "d"]: #if user enters d or e, first gather required info before performing the action
            text = input("Enter the text to work on: ")
            n = int(input("Enter the shift value (N): "))
            if choice == "e": #if encrypting, call the encrypt function and print the result
                result = encrypt(text, n)
                print(f"Encrypted text: {result}")
            else:
                result = decrypt(text, n) #if decrypting, call the decrypt function and print the result
                print(f"Decrypted text: {result}")
        else:
            print("Invalid choice. Please enter 'e' for encrypt or 'd' for decrypt, or 'done' to quit.")
main()