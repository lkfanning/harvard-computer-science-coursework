from cs50 import get_string

# Prompt user to input text

text = get_string("Text: ")

# Set variables for counters to appropriate values

letters = 0
words = 1
sentences = 0

# Calculate letter count

for i in text:
    if i.isalpha():
        letters += 1

# Calculate word count

    elif i == " ":
        words += 1

# Calculate sentence count

    elif i == "." or i == "?" or i == "!":
        sentences += 1

# Calculate Coleman-Liau Index

index = 0.0588 * (letters/words * 100) - 0.296 * (sentences/words * 100) - 15.8

# Return grade-level of text

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", round(index))