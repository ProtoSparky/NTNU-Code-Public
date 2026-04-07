# kunder.dta
Filen er satt opp av en header, og  2 sammenkoblede blokker som loopes.

Den første blokken inneholder informasjon for selve stedet, og ser sånn ut
```
KUNDE
[kundeNr]
[tlf]
[navn]
[ant gjenstander]
```
Alt innenfor brackets "`[]`" er data som vil lagres. KUNDE er bare en overskrift
i filen for å få det til å se fint ut. 
Header plasseres på toppen av filen og inneholder antall kunder

Den andre blokken ser sånn ut:

```
GJENSTAND
[gjenstandNr]
[gjenstandEnum]
[gjenstandData int/bool] #feks om den har drasele eller ikke
```

# Reelt eksempel
```
[antall kunder]
KUNDE
[kundeNr]
[tlf]
[navn]
[ant gjenstander]
GJENSTAND
[gjenstandNr]
[gjenstandEnum]
[gjenstandData int/bool]
GJENSTAND
[gjenstandNr]
[gjenstandEnum]
[gjenstandData int/bool]
GJENSTAND
[gjenstandNr]
[gjenstandEnum]
[gjenstandData int/bool]
KUNDE
[kundeNr]
[tlf]
[navn]
[ant gjenstander]
GJENSTAND
[gjenstandNr]
[gjenstandEnum]
[gjenstandData int/bool]

```
Her vil datastrukturen være for 2 kunder, der en av de har 3 gjenstander, og 
den andre har 1 gjenstand