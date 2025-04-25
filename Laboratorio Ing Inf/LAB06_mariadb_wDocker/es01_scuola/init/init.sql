-- Crea il database (se non già fatto)
CREATE DATABASE IF NOT EXISTS scuola;
USE scuola;

-- Tabella aule
CREATE TABLE aule (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

-- Tabella insegnanti
CREATE TABLE insegnanti (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    cognome VARCHAR(50) NOT NULL,
    materia VARCHAR(50)
);

-- Tabella studenti
CREATE TABLE studenti (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    cognome VARCHAR(50) NOT NULL,
    eta INT,
    id_aula INT,
    FOREIGN KEY (id_aula) REFERENCES aule(id)
);

-- Tabella verifiche (informazioni comuni dell’esame)
CREATE TABLE verifiche (
    id INT AUTO_INCREMENT PRIMARY KEY,
    titolo VARCHAR(100) NOT NULL,
    data DATE,
    id_insegnante INT,
    id_aula INT,
    FOREIGN KEY (id_insegnante) REFERENCES insegnanti(id),
    FOREIGN KEY (id_aula) REFERENCES aule(id)
);

-- Tabella di associazione: registra quali studenti hanno sostenuto la verifica e con quale voto
CREATE TABLE esiti_verifiche (
    id INT AUTO_INCREMENT PRIMARY KEY,
    id_verifica INT,
    id_studente INT,
    voto DECIMAL(3,1),
    FOREIGN KEY (id_verifica) REFERENCES verifiche(id),
    FOREIGN KEY (id_studente) REFERENCES studenti(id)
);

-- Inserimento dati nelle tabelle aule, insegnanti e studenti come prima
INSERT INTO aule (nome) VALUES ('Aula 1'), ('Aula 2'), ('Aula 3');
INSERT INTO insegnanti (nome, cognome, materia) VALUES ('Giovanni', 'Rossi', 'Matematica'), ('Luigi', 'Bianchi', 'Storia');
INSERT INTO studenti (nome, cognome, eta, id_aula) VALUES ('Paolo', 'Verdi', 15, 1), ('Maria', 'Bianchi', 14, 2), ('Marco', 'Violetto', 14, 3);

-- Inserimento di una verifica (esame)
INSERT INTO verifiche (titolo, data, id_insegnante, id_aula)
VALUES 
  ('Verifica di Matematica', '2025-04-10', 1, 1),
  ('Verifica di Matematica 2', '2025-05-11', 1, 1),
  ('Verifica di Storia', '2025-06-11', 2, 2);

-- Inserimento degli esiti: la stessa verifica svolta da più studenti
INSERT INTO esiti_verifiche (id_verifica, id_studente, voto) VALUES (1, 1, 8.5);
INSERT INTO esiti_verifiche (id_verifica, id_studente, voto) VALUES (3, 2, 7.0);
