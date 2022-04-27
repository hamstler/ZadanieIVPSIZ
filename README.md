Zadanie IV Napisz program ktory oblicza BER (Bit Error Rate) dla dwóch dowolnych plików.

Swoją pracę utrzymaj na repozytorium na github.

Twoja praca musi być udokumentowana przez kolejne commity.

Wymagania dla programu :

Program konsolowy. Jako dwa argumenty przyjmuje ścieżki do plików dla których oblicza wartość BER.

Wynik obliczeń drukowany jest w konsoli (Jako wynik podajemy: Ilość porównanych bitów, ilość różnych bitów, wynik BER, czas obliczeń)

Program tworzy plik log.txt w którym zapisuje swoje logi. Każda wiadomość rozpoczyna się od timestamp'a.

Test 1: Przygotuj dwa identyczne pliki zawierające binarnie zapisaną wartość 0x55. Każdy plik po 100 Bajtów.

Test 2: Przygotuj dwa pliki każdy po 100 bajtów. Pierwszy zawiera binarnie zapisaną wartość 0x55. Drugi plik różni się od pierwszego o dowolne 10 bitów.

Test 3: Przygotuje dwa pliki każdy po 400 MB. Pierwszy zawiera binarnie zapisaną wartość 0x55. Drugi plik zawiera binarnie zapisaną wartość 0x50.

Podaj wynik działania programu BER dla podanych plików testowych (Wyniki zapisane w pliku z logami)
