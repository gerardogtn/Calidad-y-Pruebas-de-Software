for i in range(1, 26):
    word = ""
    for c in "RLCOPY":
        word += chr((ord(c) - 64 + i) % 26 + 64)
    print word
# RLCOPY -> GARDEN
