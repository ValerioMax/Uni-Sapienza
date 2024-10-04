s = input('inserisci stringa s: ')
i = 0
j = len(s) - 1

while i <= j:
    if s.count(s[i]) <= s.count(s[j]):
        i += 1
    else:
        j -= 1
        
print(s[j])
        
    
    
    
