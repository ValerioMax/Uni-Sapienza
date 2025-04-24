Come usare il progetto:

Andiamo nella cartella del docker-compose file, creaiamo e runniamo tutti i container specificati da lui
    sudo docker-compose up --build

service A runna sul container service_a
service B runna sul container service_b
Noi interagiamo con service_b facendogli una richista all'URL (anche solo mettendolo nel browser):
    http://0.0.0.0:8000/
service_b chiamerà il service_a facendo da server intermediario e ottenuta una response da lui ce la manderà a noi

Possiamo anche runnare client.py che invia la request da codice python con FastAPI
    python3 client.py