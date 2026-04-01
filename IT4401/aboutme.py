temp = int(input("Enter a Farenheit temperature: "))
if temp < -459.67:
    print("Invalid input. A Fahrenheit temperature must not be lower than -459.67.")
else:
    convert_to = input("Convert to k (for Kelvin) or c (for Celsius): ")
    match(convert_to):
        case "k"|"K":
            kelvin = (temp - 32) * 5/9 + 273.15
            print(f"{temp} degrees Fahrenheit is {kelvin:.2f} degrees Kelvin.")
        case "c"|"C":
            celsius = (temp - 32) * 5/9
            print(f"{temp} degrees Fahrenheit is {celsius:.2f} degrees Celsius.")
        case _:
            print("Invalid input. Please enter 'k' for Kelvin or 'c' for Celsius.")
print("Program terminated.")