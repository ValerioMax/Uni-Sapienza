Come usare il progetto:

Andiamo in docker/ e creaiamo Immagine a partire dal Dockerfile e dal .dockerignore
    sudo docker build -t prova_image:1.0 .

Creaiamo e avviamo un Container a partire da questa Immagine
    sudo docker run -p 8007:8000 --name prova_container1 prova_image:1.0
In questo modo abbiamo anche collegato la porta interna del container (a sx) 8000
a quella esterna (a dx) 8007
--> per accedere al container l'app nel container aspetta requests sulla porta 8000 interna
    per fargliele arrivare noi le spediamo sulla porta 8007 (docker le inoltrerà alla 8000 interna)

Stiamo eseguendo l'app (*) "main.py" nel container docker "prova_container1"
(*): app costituita da tutti i file che ho messo nel container 
        --> lettermente copio tutto il progetto nel container

Per visualizzare response apriamo browser su
    http://localhost:8007/
(inviamo request a localhost:8007)

Possiamo anche runnare client.py che invia la request da codice python con FastAPI
    python3 client.py