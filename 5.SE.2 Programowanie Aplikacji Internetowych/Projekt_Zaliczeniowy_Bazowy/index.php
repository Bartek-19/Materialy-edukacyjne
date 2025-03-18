<html>
    <head>
        <meta charset="UTF-8">
        <title>Ogłoszenia o pracę w PL</title>
        <link rel="stylesheet" href="css/style.css">
    </head>
    <body>
        <h1 class='NaglowekStrony'>Ogłoszenia o pracę w PL - znajdź coś dla siebie!</h1>
        <div class='Wyszukiwarka'>
            <form method='POST' action='index.php'>
                <span class='ElementWyszukiwarki'>
                    <h4>Wyszukaj po frazie:</h4><br>
                    <input type='text' name='Fraza'>
                </span>
                <span class='ElementWyszukiwarki'>
                    <h4>Wynagrodzenie:</h4><br>
                    <input type='number' name='Wynagrodzenie'> - 
                    <input type='number' name='WynagrodzenieGorne'>
                </span>
                <span class='ElementWyszukiwarki'>
                    <h4>Poziom stanowiska:</h4><br>
                    <input type='checkbox' name='Doswiadczenie[]' value='1'> Praktykant <br>
                    <input type='checkbox' name='Doswiadczenie[]' value='2'> Stażysta (Intern) <br>
                    <input type='checkbox' name='Doswiadczenie[]' value='3'> Młodszy specjalista (Junior) <br>
                    <input type='checkbox' name='Doswiadczenie[]' value='4'> Specjalista (Mid) <br>
                    <input type='checkbox' name='Doswiadczenie[]' value='5'> Starszy specjalista (Senior) <br>
                    <input type='checkbox' name='Doswiadczenie[]' value='6'> Ekspert (Advanced)
                </span>
                <br>
                <input type='reset' value='Anuluj'>
                <input type='submit' name="Action" value='Wyszukaj'>
            </form>
            
        </div>
        <?php
        require_once 'klasy/Baza.php';
        require_once 'Funkcje.php';
        
        $dbh = new Baza("localhost", "root", "", "projektzaliczeniowy");
        $akcja = filter_input(INPUT_POST, 'Action', FILTER_SANITIZE_FULL_SPECIAL_CHARS);
        wyswietlenieOgloszenia($akcja, $dbh);
        ?>
    </body>
</html>
