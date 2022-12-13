import cs50

# Create main function to print hash pyramid with height of user input


def main():
    n = get_height()
    for i in range(0, n, 1):
        for j in range(0, n, 1):
            if (i + j < n - 1):
                print(" ", end="")
            else:
                print("#", end="")
        print()

# Create a function to prompt user for height input


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                break
        # Reprompt user if value entered is not an integer

        except ValueError:
            print("That's not an integer!")
    return n

# Run the main function


main()