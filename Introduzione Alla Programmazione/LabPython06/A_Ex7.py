s1 = input('inserisci stringa non vuota s1: ')
s2 = input('inserisci stringa non vuota s2: ')
i = 0
j = 0
x = ''
y = ''
z = ''
for h in s1:
    if i < len(s1):
        x = s1[i]
        sequenza1 = x
        
        if s2.count(sequenza1) > 0 and len(sequenza1) > len(z):
            z = sequenza1
            
        for h in s1:
            x = x + s1[i]
            i += 1
            sequenza1 = x
           
            
            if s2.count(sequenza1) > 0 and len(sequenza1) > len(z):
                z = sequenza1
  
print(z)

    
