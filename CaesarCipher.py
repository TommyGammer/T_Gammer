# Tommy Gammer
# Solves a caesar cipher using the brute force method but only displays the correct shift and output

from time import time
from sys import argv

with open("dictionary.txt", "r") as f:
    words = f.read().splitlines()
#print(words)

# normalize the words
dictionary = []
for word in words:
    # remove non-alphabetic characters
    for char in word:
        if (not char.isalpha()):
            word = word.replace(char, "")
    # convert to uppercase
    word = word.upper()
    # add the word to the dictionary
    dictionary.append(word)

# function that consumes time
def consume_time():
    for i in range(250000000):
        pass

# start a timer
start = time()

# get the filename
filename = argv[1]

# open the file for reading
with open(filename, "r") as f:
    # read the lines into a list
    lines = f.read().splitlines()

# makes each line as a list
for line in lines:
    line.split()

alphString = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"
# turns the string alphString into a list
alphabet = alphString.split()

        
# Sub progam that performs one shift of a caesar cipher and if the shift's words contain over 50 of the words that are in the dictionary then it prints it
def decrypt(cipher_text, shift_amount):
    n = 0
    plain_text = ""
    for letter in cipher_text:
        if letter == " ":
            plain_text += " "
        elif letter not in alphabet:
            plain_text += letter
        else:
            position = alphabet.index(letter)
            new_position = position - shift_amount
            plain_text += alphabet[new_position]
    plain_text_split = plain_text.split()
    for word in plain_text_split:
    # if the word is in the dictionary
        if (word in dictionary):
        # increment the counter
            n += 1
    if (n > len(plain_text_split) / 2):
        print("Shift = " + str(i) + ": " + plain_text)
        print(" ")

# Performs the sub program for every possible shift for each line in the file
for line in lines:
    i = 1
    n = 0
    print("Ciphertext: " + line)
    while i < 26:
        decrypt(line, i)
        i+=1


# end the timer
end = time()
# display timing results
print("Process took {} s".format(end - start))

# Use this to run code
# %Run 'Program 6.py' ciphertexts-Sample.txt
# %Run 'Program 6.py' ciphertexts.txt

# Sources Cited
# https://dev.to/ramakm/caesar-cipher-encryption-decryption-using-python-38fn
