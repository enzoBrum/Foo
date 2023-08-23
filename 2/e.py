t = int(input())
input()
first = True
last = False
for _ in range(t):
    if last:
        break
    if first:
        first = False
    else:
        print()
    
    
    anagrams = {}
    while True:
        try:
            line = input()
            if not line:
                break
        except:
            last = True
            break
    
        new_line = [c for c in line if c != ' ']
        new_line.sort()
        key = "".join(new_line)

        if key in anagrams:
            anagrams[key].add(line)
        else:
            anagrams[key] = {line}
        
    
    lines = []
    for anagram in anagrams.values():
        anagram = list(anagram)
        anagram.sort()

        for i in range(len(anagram)):
            for j in range(i+1, len(anagram)):
                lines.append((anagram[i], anagram[j]))
        
        
    
    lines.sort()
    for a, b in lines:
        print(f"{a} = {b}")


        
