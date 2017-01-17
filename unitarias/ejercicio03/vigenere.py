import sys
key = sys.argv[1]
cipher = sys.argv[2]
out = ""
special = 0

for i in range(0, len(cipher)):
    if (cipher[i] in " ."):
        out += cipher[i]
        special = special + 1
    else:
        alphabetIndex = ord(cipher[i]) - ord(key[(i-special) % len(key)])
        out += chr(alphabetIndex % 26 + 65)
print out
