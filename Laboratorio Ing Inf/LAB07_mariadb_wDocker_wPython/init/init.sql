CREATE DATABASE IF NOT EXISTS prova_db;
USE prova_db;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    email VARCHAR(255) UNIQUE NOT NULL
);

INSERT INTO users (name, email) VALUES
('Alice Rossi', 'alice@gmail.com'),
('Pino Verdi', 'pino@gmail.com'),
('Bruno Neri', 'bruno@gmail.com');