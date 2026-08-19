# AKTIVERE ELLER DEAKTIVERE GUEST ACCOUNT
Scriptet aktiverer eller deaktiverer guest account på AD server slik at brukere får logget seg inn som guest.
Er dette anbefalt? Nei, men jeg antar dette er hvordan oppgaven ønsker at dette skal gjøres.

# Syntax
## Aktivere guest account
`./program.ps1 -guestAccountState enable`

## Deaktivere guest account
`./program.ps1 -guestAccountState disable`

# Troubleshooting
## Failed to enable/disable guest account
Endringene dine ble ikke lagret på AD server.

Sjekk at du bruker en admin konto som har permissions til å endre status
