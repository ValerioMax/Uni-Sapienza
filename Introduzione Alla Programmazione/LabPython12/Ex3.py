def Ex3(file1,file2):
    f1 = open(file1, 'r', encoding = 'UTF-8')
    f2 = open(file2, 'r', encoding = 'UTF-8')
    righe1 = f1.read().strip().split('\n')
    righe2 = f2.read().strip().split('\n')
    d = {}
    d1 = {}
    d2 = {}
    for riga in righe2:
        a = riga.split(',')
        d2[a[0]] = []
        for i in range(1,len(a)):
            d2[a[0]].append(a[i])
    
    
    for riga in righe1:
        a = riga.split(',')
        d1[a[0]] = []
        for i in range(1,len(a)):
            d1[a[0]].append(a[i])
    
    print(d2.get('Carla'))
    
    for pers in d2:
        print(d2.get(pers))
        for i in d2.get(pers):


###############################################################################
 
"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['piatti1.csv','allergie1.csv'],{'Carla': 'Matriciana', 'Alessia': 'Tiramisu', 'Marco': 'Matriciana', 'Gianni': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['piatti2.csv','allergie1.csv'],{'Carla': 'Focaccia', 'Alessia': 'Tiramisu', 'Marco': 'Matriciana', 'Gianni': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['piatti1.csv','allergie2.csv'],{'Carla': 'Matriciana', 'Alessia': 'Tiramisu', 'Marco': 'Matriciana', 'Gianni': 'Nessuno', 'Flavia': 'Tiramisu'})
    counter_test_positivi += tester_fun(Ex3, ['piatti2.csv','allergie2.csv'],{'Carla': 'Focaccia', 'Alessia': 'Tiramisu', 'Marco': 'Matriciana', 'Gianni': 'Nessuno', 'Flavia': 'Tiramisu'})
    counter_test_positivi += tester_fun(Ex3, ['piatti3.csv','allergie3.csv'],{'Carla': 'Focaccia', 'Alessia': 'Tiramisu', 'Marco': 'Matriciana', 'Gianni': 'Caprese', 'Flavia': 'Tiramisu', 'Paolo': 'Focaccia'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)