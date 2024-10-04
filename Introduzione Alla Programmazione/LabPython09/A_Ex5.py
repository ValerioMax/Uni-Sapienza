def A_Ex5(filename,oggetto):
    f = open(filename,encoding='UTF-8')
    b = f.readline().strip().split(',')
    righe = f.read().split('\n')
    for riga in righe:
        a = riga.strip().split(',')
        if a[0] == oggetto:
            anno = int(b[1])
            x = 0
            for i in range(1,len(a)):
                if int(a[i]) >= x:
                    anno = int(b[i])
                    x = int(a[i])
            break
    return anno
    







    

###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex5, ['Vendite1.csv','Giubbotto'] , 2012)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite1.csv','Zaino'] , 2010)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite2.csv','Maglione'] , 2012)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite2.csv','Zaino'] , 2013)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite3.csv','Giubbotto'] , 2013)

    print('La funzione',A_Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
