def Ex3(file1,file2):
    f1 = open(file1, 'r', encoding = 'UTF-8')
    f2 = open(file2, 'r', encoding = 'UTF-8')
    righe1 = f1.read().strip().split('\n')
    righe2 = f2.read().strip().split('\n')
    d2 = {}
    for riga in righe2:
        riga = riga.split(',')
        d2[riga[0]] = set()
        for i in range(1,len(riga)):
            d2[riga[0]].add(riga[i])
            
    d1 = {}
    for riga in righe1:
        riga = riga.split(',')
        d1[riga[0]] = set()
        for i in range(2,len(riga)):
            d1[riga[0]].add(riga[i])
        d1[riga[0]] = [int(riga[1]),d1.get(riga[0])]
   
    d3 = {}
    for pers in d2:
        d3[pers] = []
        for ing in d1:
            for i in (d1.get(ing))[1]:
                if i in d2.get(pers):
                    if [ing,(d1.get(ing))[0]] in d3.get(pers):
                        d3[pers].remove([ing,(d1.get(ing))[0]])
                if i not in d2.get(pers):
                    if [ing,(d1.get(ing))[0]] not in d3.get(pers):
                        d3[pers].append([ing,(d1.get(ing))[0]])
                    else:
                        d3[pers].remove([ing,(d1.get(ing))[0]])
                        d3[pers].append([ing,(d1.get(ing))[0]])
                
                        
    print(d3)


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
