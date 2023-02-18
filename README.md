# ConsoleApp_String
Console applications for string and transformation (German):
## 2DEC

Argument in Dezimalzahl.

Handhabung:

     2DEC [x] 
     [x] .... Argument

## ABCD

Ändert oder löscht Strings einer ASCII Datei.

- Übernahme einer ASCII Datei
- Ausgabe einer modifizierten ASCII Datei

Handhabung:
        
     ABCD [input] [output] [ab] [cd] [sw]
     [input] ... Eingabe Datei
     [output] .. Ausgabe Datei 
     [ab] ...... String der zu modifizieren ist (String_alt)
     [cd] ...... String der eingefügt wird (String_neu)
     [sw] ...... (0):modifiziert (1):löscht String_alt (2):fügt ein Leerzeichen ein

Bsp: 

     ABCD input.txt output.txt .txt .asc 0
     ABCD input.txt output.txt REM 0 1
