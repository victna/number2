year = int(input("Enter a year: "))
if(year<0):
    print("Invalid input.")
else:
    if(year%4==0 and year%100!=0) or (year%400==0):
        print(f"Yes, {year} is a leap year.")
    else:
        print(f"No, {year} is not a leap year.")