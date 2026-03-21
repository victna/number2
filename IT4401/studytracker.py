
class student:
    def __init__(self, name, subject, hours):
        self.name = name
        self.subject = subject
        self.hours = hours

study_record = {}
with open('study.txt', 'r') as file:
    for line in file:
        if line.startswith("student"):
            continue
        print(line)
        temp = line.split(',')
        name = temp[0]
        subject = temp[1]
        hours = temp[2]
        newstudent = student(name, subject, hours)
        study_record.append(newstudent)
def main():
    acitve = True
    while active:
        print("Enter action (summary, add, done): ")
        choice = input("Enter your choice: ")
        match choice:
            case 'summary':
                for record in study_record:
                    print(f"{record.name} - {record.subject} - {record.hours}")
                    print("-------------------------\nTotal students: {len(study_record)}\n=========================")
            case 'add':
                name = input("Enter student name: ")
                subject = input("Enter subject: ")
                hours = input("Enter hours studied: ")
                newstudent = student(name, subject, hours)
                study_record.append(newstudent)
                print("Record added successfully.")
            case 'done':
                active = False
                print("All new study records saved. Goodbye!")
            case _:
                print("Invalid choice. Please try again.")
    with open('study.txt', 'w') as file:
        for record in study_record:
            file.write(f"{record.name},{record.subject},{record.hours}\n")
main()