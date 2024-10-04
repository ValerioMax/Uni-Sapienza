s = input('iserire stringa s: ')
while s.isdecimal() or not s.islower():
    print(s[0] + s[len(s) - 1])
    s = input('iserire stringa s: ')
print(s)
    
    
