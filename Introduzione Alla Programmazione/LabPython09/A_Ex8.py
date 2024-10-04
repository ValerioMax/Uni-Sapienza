def A_Ex8(fileName):
    f = open(fileName,encoding='UTF-8')
    righe = f.read().strip().split('\n')
    lista = []
    lista1 = []
    for numriga in range(1,len(righe) + 1):
        riga = righe[numriga - 1]
        riga = list(riga)
        x = 0
        for car in riga:
            if car.isalpha() and car.isupper():
                x += 1
        numcar = x
        lista.append(numcar)
        lista1.append((numriga,numcar))
    carmax = max(lista)
    for i in lista1:
        if i[1] == carmax:
            index = numriga
    return numriga
        




    
 
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, ["file1.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["file2.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["file3.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["file4.txt"] , 3)
    counter_test_positivi += tester_fun(A_Ex8, ["file5.txt"] , 3)

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
