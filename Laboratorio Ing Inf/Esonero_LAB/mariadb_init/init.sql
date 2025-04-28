-- da modificare e farlo con un for che parsa il file tsv

CREATE DATABASE IF NOT EXISTS esonero_db;
USE esonero_db

CREATE TABLE movies (
    id INT AUTO_INCREMENT PRIMARY KEY,
    titolo VARCHAR(255) NOT NULL,
    regista VARCHAR(255) NOT NULL,
    eta_autore INT,
    anno INT,
    genere VARCHAR(255),
    piattaforma_1 VARCHAR(255),
    piattaforma_2 VARCHAR(255)
);

INSERT INTO movies (titolo, regista, eta_autore, anno, genere, piattaforma_1, piattaforma_2) VALUES
('Inception', 'Christofer Nolan', 54, 2010, 'Fantascienza', 'Amazon Prime Video', 'NOW'),
('Parasite', 'Bong Joon-ho', 55, 2019, 'Dramma', 'Netflix', NULL),
('Interstellar', 'Christofer Nolan', 54, 2014, 'Fantascienza', 'Paramount+', 'Amazon Prime Video');