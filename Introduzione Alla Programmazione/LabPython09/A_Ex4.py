def A_Ex4(filename,anno):
    f = open(filename,encoding='UTF-8')
    
    b = f.readline()
    b = b.strip().split(',')
    righe = f.read().split('\n')  
    j = 0
    for i in range(1,len(b)):
        if anno == int(b[i]):
            j = i
            break
        
    lista = []
    for riga in righe:
        a = riga.strip().split(',')
        lista.append((a[0],int(a[j])))

    lista1 = []    
    for riga in righe:
        a = riga.strip().split(',')
        lista1.append(int(a[j]))

    mass = max(lista1)

    lista2 = []
    for i in lista:
        if mass in i:
            lista2.append((i[0],i[1]))

    x = 'a'

    for i in lista2.copy():
        if i[0].lower() > x:
            x = i[0]
    return x
    
            

    






    
     
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex4, ['Vendite1.csv',2012] , 'Giubbotto')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite2.csv',2012] , 'Maglione')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite2.csv',2013] , 'Zaino')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite3.csv',2011] , 'Giubbotto')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite3.csv',2010] , 'Cellulare')
    
    print('La funzione',A_Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
