# Gruppe 34 prosjektoppgave

# PDF filer og testdata
## pdf
Her er alle pdf filene for testing og dta dokumentasjon

[Presiseringer](./PDF_FILER/Presiseringer.pdf)

[DTA fil dokumentasjon](./PDF_FILER/DTA%20filene.pdf)


[SO testing](./PDF_FILER/SO_testing.pdf)

[GF testing](./PDF_FILER/GF_testing.pdf)

[KN testing](./PDF_FILER/KN_testing.pdf)

## testdata
Du kan finne testdata i mappen [`./kopi_av_testdata`](./kopi_av_testdata/)
Her garanteres det at testdataen spesifisert i oppgaven er lagret, og disse kan kopieres til
root mappen av prosjektet for å ta testdataen i bruk. 


# Begrensninger
- K N menyvalg - valgte å bruke lesint fra 0 - 9 i 8 siffer istedenfor å sjekke at tlf er faktisk valid
- Vi antar at både sykkel og tralle har samme pris selv om konfigurasjonene dems endres
- Sted string sier at stedets unike identifikasjon er "ID/Navn", altså at begge kan være det samme
- Vi har valgt å ikke sette begrensninger på kunde navnet når det lages, så kundenavnet kan være tomt og det er lov. 
- Ikke alle funksjoner kan sorteres alfabetisk fordi man kan ikke kjøre en funksjon som utnytter noe som er definert under den selv

# Notes
alt her er temporary 

- Store deler av koden burde be skrevet om i en mer presis måte
- `Sted::lesStedFraFil` setter gjenstand enum manuelt, men kanskje all setting av enum burde flyttes til constructor av gjenstanden
- Ta en titt på `finnGjenstand` i globale funksjoner cpp
- `Kunde::sokGjenstand` virker som har for mange returns.

# TODO

* [X] Fylle ut alle testing word doc
* [X] Fil lesing
* [X] Fil skriving
* [X] legge til søke funskjon for gjenstander som lånes fra kunder (G F meny)
* [X] fikse bug som gjør at du MÅ lage minst en av gjenstandene for et gitt sted
* [X] G S meny
* [X] K H meny
* [X] K L meny
* [X] K S meny
* [X] S O meny
* [X] S S meny
* [X] Kode må sorteres alfabetisk
* [X] legge på @see
