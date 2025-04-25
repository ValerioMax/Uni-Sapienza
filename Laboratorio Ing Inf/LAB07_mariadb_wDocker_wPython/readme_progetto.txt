Installare pacchetti necessari
    sudo apt update
    sudo apt install libmariadb-dev
    pip install mariadb

Creare una cartella da montare per la persistenza del container
In /home/valerio/
    mkdir mariadb_data1

    chmod 0777 mariadb_data1

Creare container "lab07"
    sudo docker run --name lab07 \
        -e MYSQL_ROOT_PASSWORD=rootpassword \
        -p 3304:3306 \               
        --volume /home/valerio/mariadb_data1/:/var/lib/mysql:Z \
        -d mariadb:11.7.2-ubi9

Connettersi al DB dentro al container
    mariadb -h 127.0.0.1 -P 3304 -u root -p

Creare il database (con lo stesso nome datogli nel file init.sql)
    CREATE DATABASE prova_db;

Uscire con CTRL+D

Andare nella cartella init/
Eseguire lo script .sql nel DB prova_db (init.sql popola il DB)
    mariadb -h 127.0.0.1 -P 3304 -u root -p prova_db < init.sql

Ora se ci riconnette al mariadb nel container si potranno fare query
    mariadb -h 127.0.0.1 -P 3304 -u root -p

Stessa cosa se si lancia script.py
    python3 script.py