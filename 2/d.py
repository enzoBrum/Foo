while True:
    line = input()

    if line == "DONE":
        break

    new_line = ""
    for c in line:
        if c.isalpha():
            new_line += c.lower()

    l = 0
    r = len(new_line) - 1

    success = True
    while l < r:
        if new_line[l] != new_line[r]:
            success = False
            break

        l += 1
        r -= 1
    
    if success:
        print("You won't be eaten!")
    else:
        print("Uh oh..")
    