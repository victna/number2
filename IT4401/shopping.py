# shopping.py
# HW08 - Shopping List Program
# Author: <Your Name>
def main():
    filename = "prices.txt"
    try:
        with open(filename, "r") as f:
            line_number = 0
            for line in f:
                line_number += 1
                line = line.strip()
                # Process only if line is not empty
                if line != "":
                    parts = line.split(",")
                    # Check if there are exactly two parts
                    if len(parts) != 2:
                        print(f'Line {line_number}: invalid format — expected "name, price"')
                        continue
                    name = parts[0].strip()
                    price_str = parts[1].strip()
                    try:
                        price = float(price_str)
                        print(f"{name} ........ ${price:.2f}")
                    except ValueError:
                        print(f'Line {line_number}: price is not a number ("{price_str}")')
    except FileNotFoundError:
        print(f"Error: Cannot find the file '{filename}'.")
main()