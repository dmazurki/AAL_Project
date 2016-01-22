-------------------------------------------------------------------------------------------------------
1. Autor projektu
-------------------------------------------------------------------------------------------------------
Imię i nazwisko: Damian Mazurkiewicz
Nr albumu: 261471

-------------------------------------------------------------------------------------------------------
2. Opis problemu
-------------------------------------------------------------------------------------------------------
Każdy egzemplarz pewnego urządzenia składa się z k różnych części. Są one zgromadzone,
jako nieuporządkowana sekwencja, w długim magazynie. Uporządkować je tak, aby utworzyły k-elementowe,
wewnętrznie uporządkowane komplety, potrzebne do zbudowania kolejnych egzemplarzy urządzenia. Jeśli liczby
poszczególnych części są nierówne, części nadmiarowe mogą pozostać nieuporządkowane. Części są przenoszone
za pomocą suwnicy, zawsze grupami po k sąsiadujących ze sobą części, z dowolnego miejsca sekwencji na jej
koniec, bez zmiany ich uporządkowania, a następnie końcowa część sekwencji jest dosuwana do przodu, aby
wypełnić powstałą lukę. Ułożyć plan pracy suwnicy, dyktujący w kolejnych ruchach, którą grupę k części
przemieścić na koniec sekwencji. Wykonać jak najmniejszą liczbę ruchów. Porównać czasy obliczeń i wyniki
różnych metod.

-------------------------------------------------------------------------------------------------------
3. Parametry aktywacji programu.
-------------------------------------------------------------------------------------------------------
Podawanie parametrów nie jest obowiązkowe przy uruchaminaniu programu,
w razie nie podania ich zostaną im przypisane wartości domyślne.

Lista parametrów:

//pomocnicze
-help  (domyślnie: wyłączona)
opis: Program po uruchomieniu informację o tym pliku.


//tryby działania
-user_input (domyślnie: włączone)
opis: Aktywacja trybu działania dla konkretnych danych podanych przez użytkownika (w strumieniu wejściowym lub
z pliku tekstowego). W trakcie wykonania programu w tym trybie można podać dowolną ilość danych wejściowych
oznaczających początkowy stan linii produkcyjnej, każda z nich powinna być oddzielona liczbą ujemną.
Każdy element na linii produkcyjnej musi być reprezentowany przez liczbę dziesiętna. Elementy powinny być
oddzielone spacją lub znakiem nowej linii.
przykład użycia: ./sorter -uset_input 0 1 0 1 1 2 2 0 1 -1   3 2 1 0 3 3 3 2 1 0 -1

-generator (domyslnie: wyłączone)
opis: Ten tryb wykonania sprowadza się do rozwiązania jednego problemu o parametrach n,k. W którym
początkowy stan linii produkcyjnej jest generowany losowo.

-presentation (domyślnie: wyłączone)
opis: Tryb wspiera weryfikację szacowanej złożoności czasowej, umożliwia tabelaryczne przedstawienie
czasów pomiarów dla zadanych wielkości problemów.

//wybór algorytmu
-basic_algorithm (domyślnie: włączone)
opis: Do sortowania używany będzie algorytm numer 1.

-pattern_seeking (domyślnie wyłączone)
opis: Do sortowania będzie używany algorytm nr 2 ( z wyszukiwaniem posortowanych podciągów).


//parametry problemu
-n [wartość] (domyślnie n = 25)
opis: Ilość elementów na linii produkcyjnej (opcja może być przydatna w trybie wykonania  "-generator").
przykład użycia: ./sorter -generator -n 100

-k [wartość] (domyślnie k = 3)
opis: Ilość elementów wchodzących w skład jednego urządzenia (opcja może być przydatna w trybach
wykonania "-generator" i "-presentation").

//informacje o rozwiązaniu
-time
opis: Przy aktywacji tej opcji jest wyświetlany czas każdego rozwiązania w milisekundach.

-list_steps
opis: Przy aktywacji tej opcji dla każdego rozwiązania wyświetlana jest lista kroków
(w postaci numerów oznaczających indeks pierwszych z k przesuwanych elementów).

-steps
opis: Przy aktywacji tej opcji dla każdego rozwiązania wyświetlana jest ilość króków
jaka potrzebna była niego potrzebna.

-result
opis: Wyświetlenie linii produkcyjnej po posortowaniu.

-------------------------------------------------------------------------------------------------------
4. Pliki źródłówe.
-------------------------------------------------------------------------------------------------------

Algorithm.cpp, Algorithm.h - Klasa algorytmu, który sortuje komponenty na linii produkcyjnej według ograniczeń
wynikających z treści zadania.

Application.cpp, Application.h - Klasa zarządzająca wykonaniem programu, interpretuje argumenty podane na wejściu
oraz dane podawane przez  użytwownika, uruchamia algorytm sortowania i wyświetl wyniki.

InputDataGenerator.cpp, InputDataGenerator.h - klasa używana do generacji początkowych stanów linii produkcyjnych
w formie list liczb

Options.cpp, Options.h - Klasa odpowiedzialna za wyodrębnienie opcji podanych w liście argumentów przez użytkownika.
przechowywanie ich oraz gwarantowanie prostego dostępu do nich.


-------------------------------------------------------------------------------------------------------
5. Założenia projektowe.
-------------------------------------------------------------------------------------------------------

-Nie jest gwarantowane to, że wszystkie elementy zostaną posortowane. Dla n elementów na linii produkcyjnej
i k elementów wchodzących w skład urządzenia, k ostatnich elementów może zostać nieposortowanych, nawet
gdy istnieją jeszcze potrzebne elementy.

-Linia produkcyjna jest reprezentowana jako lista zmiennych typu int. Przy czym 0 oznacza pierwszy element kompletu
a każdy kolejny w posortowanym komplecie jest większy o 1 od poprzedniego.

