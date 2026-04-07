# Steder.dta

Filen er satt opp av en header, og  2 sammenkoblede blokker som loopes.

Den første blokken inneholder informasjon selve stedet, og ser sånn ut
```
STED
[stedNavn]
[beskrivelse]
[tlf]
[inntjenteKr]
[antall gjenstander]

``` 
Alt innenfor brackets "`[]`" er data som vil lagres. STED er bare en overskrift
i filen for å få det til å se fint ut. 

Den andre blokken ser sånn ut:
```
TRALLE # Her kan det stå sykkel, eller elsparkesykkel
[gjenstand enum]
[gjenstand nr]
[attributt bool/int] #her vil det stå om den har drasele, tilhenger, etc
```

# Reelt eksempel


```
[siste gjenstand ID]
[antall steder]
STED
[stedNavn]
[beskrivelse]
[tlf]
[inntjenteKr]
[antall gjenstander]
TRALLE
[gjenstand enum]
[gjenstand nr]
[attributt bool/int]
TRALLE
[gjenstand enum]
[gjenstand nr]
[attributt bool/int]
SYKKEL
[gjenstand enum]
[gjenstand nr]
[attributt bool/int]
STED
[stedNavn]
[beskrivelse]
[tlf]
[inntjenteKr]
[antall gjenstander]
ELSPARKESYKKEL
[gjenstand enum]
[gjenstand nr]
[attributt bool/int]

```
Her har vi 2 steder, der ett av dem har 2 traller og en sykkel, og et til sted med bare en elsparkesykkel.
Ingen reelle verdier er satt pga lesbarhet