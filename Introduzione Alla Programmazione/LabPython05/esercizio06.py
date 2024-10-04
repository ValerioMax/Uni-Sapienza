s = input('inserisci stringa: ')
y = 0
for i in range(0,len(s)):
    x = s.rfind(s[i]) - i
    if x > y:
        z = x
        y = x
print(z)
    
            

