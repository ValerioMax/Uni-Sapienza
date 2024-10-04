def Ex1(file):
    import re
    f = open(file, 'r', encoding = 'UTF-8')
    testo = f.read()
    print(testo)
    pattern = r'([a-zA-Z])[a-zA-Z]*([a-zA-Z]) +\1[a-zA-Z]*\2'
    c = 0
    for coppia in re.finditer(pattern,testo,re.IGNORECASE):
        c += 1
        print(coppia.group())
    return c






    
    
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex1, ["file1_1.txt"] , 1)
    counter_test_positivi += tester_fun(Ex1, ["file1_2.txt"] , 2)
    counter_test_positivi += tester_fun(Ex1, ["file1_3.txt"] , 3)
    counter_test_positivi += tester_fun(Ex1, ["file1_4.txt"] , 3)
    counter_test_positivi += tester_fun(Ex1, ["file1_5.txt"] , 5)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
