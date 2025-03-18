-- Plik zawierający kod SQL wykorzystany do utworzenia tabel w bazie danych obsługującej ten projekt

CREATE TABLE IF NOT EXISTS Doswiadczenie (
    Id SMALLINT UNIQUE NOT NULL,
    Nazwa VARCHAR(10) UNIQUE NOT NULL
    PRIMARY KEY(Id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS Adres (
    Id INT UNIQUE NOT NULL AUTO_INCREMENT,
    KodPocztowy CHAR(5) NOT NULL,
    Miejscowosc VARCHAR(20) NOT NULL,
    Ulica VARCHAR(20) NOT NULL,
    Numer SMALLINT NOT NULL,
    PRIMARY KEY(Id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS Pracodawca (
    Id INT UNIQUE NOT NULL AUTO_INCREMENT,
    Nazwa VARCHAR(30) UNIQUE NOT NULL,
    Opis VARCHAR(100) NOT NULL,
    AdresId INT,
    Email VARCHAR(20) UNIQUE NOT NULL,
    Haslo VARCHAR(255) NOT NULL,
    Login VARCHAR(20) UNIQUE NOT NULL,
    PRIMARY KEY(Id),
    FOREIGN KEY(AdresId) REFERENCES Adres(Id) ON DELETE SET NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

SELECT p.Id, p.Nazwa, p.Opis, p.Email, a.KodPocztowy, a.Miejscowosc, a.Ulica, a.Numer FROM
    Pracodawca p JOIN Adres a ON p.AdresId

CREATE TABLE IF NOT EXISTS Ogloszenie (
    Id INT UNIQUE NOT NULL AUTO_INCREMENT,
    Nazwa VARCHAR(30) NOT NULL,
    Opis VARCHAR(200) NOT NULL,
    Wynagrodzenie INT NOT NULL,
    WynagrodzenieGorne INT,
    PracodawcaId INT NOT NULL,
    DoswiadczenieId SMALLINT,
    PRIMARY KEY(Id),
    FOREIGN KEY(PracodawcaId) REFERENCES Pracodawca(Id) ON DELETE CASCADE,
    FOREIGN KEY(DoswiadczenieId) REFERENCES Doswiadczenie(Id) ON DELETE SET NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS Wytyczne (
    Id INT UNIQUE NOT NULL AUTO_INCREMENT,
    Kategoria ENUM('Wymagania', 'Dodatkowo', 'Obowiazki') NOT NULL,
    Opis VARCHAR(30) NOT NULL,
    OgloszenieId INT NOT NULL,
    PRIMARY KEY(Id),
    FOREIGN KEY(OgloszenieId) REFERENCES Ogloszenie(Id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS Zalogowani ( 
    SesjaId VARCHAR(100) UNIQUE NOT NULL, 
    PracodawcaId INT UNIQUE NOT NULL, 
    OstatniaAktualizacja datetime NOT NULL, 
    PRIMARY KEY (SesjaId)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Wprowadzenie danych do tabeli 'Doswiadczenie', zawierającej poziomy doświadczenia stanowisk
INSERT INTO Doswiadczenie VALUES (1, 'Apprentice'), (2, 'Intern'), (3, 'Junior'), (4, 'Mid'), (5, 'Senior'), (6, 'Advanced');

-- Polecenia wyszukujące ogłoszenia

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id; 
-- Wybranie wszystkich ogloszen

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE p.Id = $pracodawcaID;
-- Wybranie ogłoszeń określonego pracodawcy

SELECT o.Nazwa, o.Opis, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa, 
       p.Opis, p.Email, a.KodPocztowy, a.Miejscowosc, a.Ulica, a.Numer, d.Nazwa
FROM Ogloszenie o
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Adres a ON p.AdresId = a.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE o.Id = $id;
-- Wybranie okreslonego ogloszenia

SELECT Kategoria, Opis FROM Wytyczne WHERE OgloszenieId = $id;
-- Wybranie wytycznych okreslonego ogloszenia

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE o.Nazwa LIKE '%$fraza%' 
OR o.Opis LIKE '%$fraza%'
OR d.Nazwa LIKE '%$fraza%'
OR p.Nazwa LIKE '%$fraza%' 
OR P.Opis LIKE '%$fraza%'
OR o.Id IN ( SELECT OgloszenieId FROM Wytyczne WHERE Wytyczne.Opis LIKE '%$fraza%' );
-- Wyszukiwanie po frazie

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE o.WynagrodzenieGorne IS NOT NULL AND o.Wynagrodzenie >= $Wmin AND o.WynagrodzenieGorne <= $Wmax 
OR o.WynagrodzenieGorne IS NULL AND o.Wynagrodzenie >= $Wmin AND o.Wynagrodzenie <= $Wmax;
-- Wyszukiwanie po wynagrodzeniu górnym i dolnym

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE o.WynagrodzenieGorne IS NOT NULL AND O.WynagrodzenieGorne <= $Wmax 
OR o.WynagrodzenieGorne IS NULL AND o.Wynagrodzenie <= $Wmax;
-- Wyszukiwanie po wynagrodzeniu górnym

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE o.Wynagrodzenie >= $Wmin;
-- Wyszukiwanie po wynagrodzeniu dolnym

SELECT o.Id, o.Nazwa, d.Nazwa, o.Wynagrodzenie, o.WynagrodzenieGorne, p.Nazwa FROM Ogloszenie o 
JOIN Pracodawca p ON o.PracodawcaId = p.Id
JOIN Doswiadczenie d ON o.DoswiadczenieId = d.Id
WHERE d.Id = $doswiadczenieID;
-- Wyszukiwanie po doświadczeniu

INSERT INTO Adres(KodPocztowy, Miejscowosc, Ulica, Numer) VALUES ($i1, $i2, $i3, $i4);
-- Wprowadzenie Adresu

INSERT INTO Pracodawca(Nazwa, Opis, AdresId, Email, Haslo, Login) 
VALUES ($a1, $a2, (
    SELECT MAX(Id) FROM Adres 
    WHERE KodPocztowy LIKE '$i1' 
    AND Miejscowosc LIKE '$i2' 
    AND Ulica LIKE '$i3' 
    AND Numer = $i4), 
$a4, $a5, $a6);
-- Wprowadzenie Pracodawcy

INSERT INTO Ogloszenie(Nazwa, Opis, Wynagrodzenie, WynagrodzenieGorne, PracodawcaId, DoswiadczenieId) 
VALUES ($a1, $a2, $a3, $a4, $a5, $a6);
-- Wprowadzenie ogloszenia