
class Student:
    def __init__(self, name, subject, hours):
        self.name = name
        self.subject = subject
        self.hours = hours
def main():
    study_record = load_records()
    active = True
    while active:
        print("Enter action (summary, add, done): ")
        choice = input("Enter your choice: ")
        match choice:
            case 'summary':
                for record in study_record:
                    print(f"{record.name} - {record.subject} - {record.hours}")
                print(f"-------------------------\nTotal students: {len(study_record)}\n=========================")
            case 'add':
                try:
                    userInput = input("Enter student name, subject, and hours studied (comma-separated): ").split(',')
                    if len(userInput) != 3:
                        print("Invalid format.")
                        continue
                    name, subject, hours = userInput
                    name = name.strip()
                    subject = subject.strip()
                    hours = float(hours.strip())
                except ValueError:
                    print(f"Hours entered: {hours}")
                    print("Invalid hours value. Please enter a number.")
                    continue
                newstudent = Student(name, subject, hours)
                if any(record.name == name and record.subject == subject for record in study_record):
                    print("Record already exists.")
                    continue
                study_record.append(newstudent)
                with open('study.txt', 'w') as file:
                    for record in study_record:
                        file.write(f"{record.name},{record.subject},{record.hours}\n")
                print("Record added successfully.")
            case 'done':
                active = False
                print("All new study records saved. Goodbye!")
            case _:
                print("Invalid option. Please choose: summary, add, or done.")
def load_records():
    study_record = []
    with open('study.txt', 'r') as file:
        for line in file:
            if line.startswith("student"):
                continue
            print(line)
            temp = line.split(',')
            name = temp[0].strip()
            subject = temp[1].strip()
            hours = temp[2].strip()
            newstudent = Student(name, subject, hours)
            study_record.append(newstudent)
    return study_record
main()