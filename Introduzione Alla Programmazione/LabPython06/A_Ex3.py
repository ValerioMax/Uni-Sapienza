x = 1
y = 1
for i in range(1,9):
    
    
    linea = ''
    for i in range(1,9):
        
        z = x * y
        y += 1
        numero = ''
        
        for i in range(len(str(z)) + 1):
            quoziente = z // 8
            resto = z % 8
            numero = str(numero) + str(resto)
            z = quoziente
        numero = numero[len(numero) - 1::-1]
        
        linea = linea + '[' + numero + '] , '
    linea = linea[0:len(linea) - 3]
    print(linea)
    y = 1
    x += 1
