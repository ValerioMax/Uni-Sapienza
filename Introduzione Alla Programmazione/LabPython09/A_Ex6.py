def A_Ex6(filename):
    f = open(filename,encoding='UTF-8')
    b = f.readline().strip().split(',')
    righe = f.read().split('\n')
    lista = []
    lista1 = []
    for i in range(1,len(b)):
        x = 0
        for riga in righe:
            a = riga.strip().split(',')
            x = x + int(a[i])
        somma = x
        lista.append(somma)
        lista1.append((int(b[i]),somma))
    sommamax = max(lista)
    for i in lista1:
        if i[1] == sommamax:
            annomax = i[0]
    return annomax
    
    







    
 
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex6, ['Vendite1.csv'] , 2010)
    counter_test_positivi += tester_fun(A_Ex6, ['Vendite2.csv'] , 2013)
    counter_test_positivi += tester_fun(A_Ex6, ['Vendite3.csv'] , 2013)
    counter_test_positivi += tester_fun(A_Ex6, ['Vendite4.csv'] , 2020)
    counter_test_positivi += tester_fun(A_Ex6, ['Vendite5.csv'] , 2022)

    print('La funzione',A_Ex6.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
