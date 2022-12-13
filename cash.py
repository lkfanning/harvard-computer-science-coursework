from cs50 import get_float

# Prompt user for the change they are owed

while True:
    cents = get_float("Change owed: ")
    if cents > 0:
        break

cents = round(cents * 100)

count = 0

# Calculating number of quarters

while cents >= 25:
    cents = cents - 25
    count += 1

# Calculating number of dimes

while cents >= 10:
    cents = cents - 10
    count += 1

# Calulating number of nickels

while cents >= 5:
    cents = cents - 5
    count += 1

# Calculating number of pennies

while cents >= 1:
    cents = cents - 1
    count += 1

print(count)