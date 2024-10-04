def Ex8(file):
    f = open(file, 'r', encoding = 'UTF-8')
    testo = f.read()
    righe = testo.strip().split('\n')
    pattern = r'[A-Z][A-Z][A-Z]\ ?[A-Z][A-Z][A-Z]\ ?(\d\d)([A-Z])(\d\d) ?[A-Z]\d\d\d[A-Z]'
    lista = []
    for riga in righe:
        m = re.search(pattern,riga)
        if m:
            anno = int(m.group(1))
            mese = m.group(2)
            giorno = int(m.group(3))
            if mese=='A' or mese=='B' or mese=='C' or mese=='D' or mese=='E' or mese=='H' or mese=='L' or mese=='M' or mese=='P' or mese=='R' or mese=='S' or mese=='T':
                if mese == 'A':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '01' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '01' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '01' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '01' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '01' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '01' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '01' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '01' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')      
                elif mese == 'B':
                    if anno <= 20:
                        if giorno <= 28 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '02' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '02' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '02' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '02' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 28 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '02' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '02' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '02' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '02' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'C':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '03' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '03' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '03' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '03' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '03' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '03' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '03' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '03' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'D':
                    if anno <= 20:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '04' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '04' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '04' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '04' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '04' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '04' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '04' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '04' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'E':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '05' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '05' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '05' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '05' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '05' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '05' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '05' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '05' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'H':
                    if anno <= 20:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '06' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '06' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '06' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '06' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '06' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '06' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '06' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '06' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'L':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '07' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '07' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '07' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '07' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '07' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '07' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '07' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '07' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'M':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '08' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '08' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '08' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '08' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '08' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '08' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '08' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '08' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'P':
                    if anno <= 20:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '09' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '09' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '09' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '09' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '09' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '09' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '09' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '09' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'R':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '10' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '10' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '10' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '10' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '10' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '10' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '10' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '10' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'S':
                    if anno <= 20:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '11' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '11' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '11' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '11' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 30 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '11' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '11' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '11' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '11' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
                elif mese == 'T':
                    if anno <= 20:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '12' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '12' + '/' + '20' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '12' + '/' + '20' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '12' + '/' + '20' + str(anno))
                        else:
                            lista.append('Giorno errato')
                    else:
                        if giorno <= 31 and giorno >= 1:
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '12' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '12' + '/' + '19' + str(anno))
                        elif giorno >= 41 and giorno <= 71:
                            giorno = giorno - 40
                            if giorno >= 10:
                                lista.append(str(giorno) + '/' + '12' + '/' + '19' + str(anno))
                            else:
                                lista.append('0' + str(giorno) + '/' + '12' + '/' + '19' + str(anno))
                        else:
                            lista.append('Giorno errato')
            else:
                lista.append('Mese errato')
        else:
            lista.append('Codice errato')
        f.close()
    return lista  
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex8, ["codici1.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato'])
    counter_test_positivi += tester_fun(Ex8, ["codici2.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato'])
    counter_test_positivi += tester_fun(Ex8, ["codici3.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato', '01/11/1921'])
    counter_test_positivi += tester_fun(Ex8, ["codici4.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato', '01/11/1921', '01/11/1931'])
    counter_test_positivi += tester_fun(Ex8, ["codici5.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato', '01/11/1921', '01/11/1931', 'Codice errato', 'Giorno errato'])

    print('La funzione',Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
