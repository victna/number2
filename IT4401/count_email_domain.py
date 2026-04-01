def extract_domain(email):
    if '@' in email:
        return email.split('@')[1]
    return None
def count_email_domain(fileName, domain):
    filePath = fileName
    domain_count = 0
    try:
        with open(filePath, 'r') as file:
            content = file.read()       
    except FileNotFoundError:
        print("File not found.")
        return
    emails = content.split() #splits the content into a list of words
    for email in emails: #iterates through the list of words
        if '@' in email: #checks if the word contains an '@' symbol
            email_domain = extract_domain(email) #extracts the domain from the email address
            if email_domain == domain: #checks if the domain matches the input domain
                domain_count += 1 #increments the count for the domain
    print(f"In the file {filePath} there are {domain_count} email addresses with the domain '{domain}'.")
def main():
    fileName = input("Enter the file name: ").strip() #takes input for the file name
    domain = input("Enter the email domain to count: ").strip().lower() #takes input for the email domain
    count_email_domain(fileName, domain)