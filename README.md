 # Aplikacja pizzeri do składania zamówień 
 
 
Informatyka IV, lab.2  
Krzysztof Pięta 
Damian Wawrzkowicz Andrzej Sabat 
Cel projektu: 
Celem projektu jest stworzenie aplikacji do obsługi zamówień w małym lokalu gastronomicznym typu pizzeria. Uzytkownik może wybierać spośród dostępnych potraw, złożyć zamówienie oraz otrzymać paragon. 
 
## Założenia projektu: 
-	wybór sposobu odbioru zamówienia 
-	baza kodów pocztowych z możliwością aktualizacji dla większych rejonów 
-	możliwość generowania paragonu 
-	koszyk z wybranymi przez użytkownika produktami 
-	menu potraw 
-	możliwość edycji wybranej potrawy 
-	podczas generowania paragonu obliczanie kwot podatku VAT dla zamówionych dań  
 
## Użyte technologie: 
Aplikacja została napisana w C++ w środowisku programistycznym Qt Creator, które jest dedykowane tworzeniu aplikacji okienkowych w tym języku. 

## Opis aplikacji: 
Po uruchomieniu użytkownik może wybrać z dostępnych opcji (dowóz, na miejscu) jaki rodzaj zamówienia chce złożyć. Następnie wprowadza dane zależne od wyboru którego dokonał. Po przejściu dalej użytkownik ma możliwosc wyboru dania które chce zamówić z menu. Wybór dania automatycznie otwiera okno z możliwoscią konfiguracji zamówionego posiłku poprzez zmianę rozmiaru, ciasta, ilości sztuk oraz indywidualną konfigurację dodatków. Wszelkie zmianu wprowadzone przez użytkownika wpływają na cenę zamówienia która automatycznie zmienia się wraz z modyfikacją zamówienia. Po zatwierdzeniu wyboru można wybrać kolejne danie lub przejść do kolejnego okna. Dalej znajduję się menu w postaci listy z dostepnymi napojami. Wybranie elementu z listy oraz użycie przycisku „Dodaj do koszyka” dodaje napój do zamówienia.  
 
W każdym momencie działania aplikacji w górnej częsci okna dostępny jest przycisk wyświetlający stan naszego koszyka. Po wyborze napoju wyświetla się widok z podsumowaniem zamówienia, danymi zamawiającego oraz łączną kwotą za zamówienie. Po zatwierdzeniu zamówienia użytkownikowi generowany jest paragon ze szczegółowymi danymi zamówienia oraz obliczoną kwotą. 

## Instrukcja: 
Przy uruchomieniu aplikacji poprzez plik wykonywalny .exe wymagane są dodatkowe biblioteki załączone w repozytorium, które powinny znajdować się w folderze razem z plikiem wykonywalnym. Brak którejś z wymaganych bibliotek spowoduje bład. 

## Wymagane biblioteki: 
-	Qt5Core.dll 
-	Qt5Gui.dll 
-Qt5Guid.dll 
-	Qt5Widgets.dll 
-	libEGL.dll 
-	libgcc_s_dw2-1.dll 
-	libstdc++-6.dll 
-	libwinpthread-1.dll 
-	zipcodes.txt (lista kodów pocztowych) 
  
