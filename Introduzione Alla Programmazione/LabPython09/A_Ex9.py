def A_Ex9(fileName,squadra):
    f = open(fileName,encoding='UTF-8')
    b = f.readline().split(',')
    righe = f.read().split('\n')
    x = 0
    for riga in righe:
        a = riga.split(',')
        if squadra in a:
            if squadra == a[0]:
                if a[2] > a[3]:
                    x += 3
                elif a[2] == a[3]:
                    x += 1
            elif squadra == a[1]:
                if a[2] < a[3]:
                    x += 3
                elif a[2] == a[3]:
                    x += 1
    return x
 
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex9, ["partite1.csv",'Chelsea'] , 3)
    counter_test_positivi += tester_fun(A_Ex9, ["partite1.csv",'Tottenham'] , 1)
    counter_test_positivi += tester_fun(A_Ex9, ["partite2.csv",'Arsenal'] , 4)
    counter_test_positivi += tester_fun(A_Ex9, ["partite2.csv",'Bayern'] , 0)
    counter_test_positivi += tester_fun(A_Ex9, ["partite3.csv",'Bayern'] , 4)

    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
