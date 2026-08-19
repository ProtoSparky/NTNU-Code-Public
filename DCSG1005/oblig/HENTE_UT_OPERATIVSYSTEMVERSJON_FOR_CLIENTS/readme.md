# Hente ut operativystemversjon for clients
Viser OS versjon i tabell. Støtter søk og filtrering

# Syntax
## Vis alle alle clients på AD
````
./program.ps1

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
DC1  Windows Server 2025 Standard Evaluation 10.0 (26100)
MGR  Windows 11 Enterprise Evaluation        10.0 (26100)
SRV1 Windows Server 2025 Standard Evaluation 10.0 (26100)
CL1  Windows 11 Enterprise Evaluation        10.0 (26100)
````

## Søk etter en spesifikk client
````
/program.ps1 -name dc1

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
DC1  Windows Server 2025 Standard Evaluation 10.0 (26100)
````

## Vis de første x antall clients
````
./program.ps1 -head 2

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
DC1  Windows Server 2025 Standard Evaluation 10.0 (26100)
MGR  Windows 11 Enterprise Evaluation        10.0 (26100)
````

## Vis de siste x antall clients
````
./program.ps1 -tail 3

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
MGR  Windows 11 Enterprise Evaluation        10.0 (26100)
SRV1 Windows Server 2025 Standard Evaluation 10.0 (26100)
CL1  Windows 11 Enterprise Evaluation        10.0 (26100)
````

## Eller en kombinasjon av kommandoene
````
./program.ps1 -head 3 -tail 1

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
SRV1 Windows Server 2025 Standard Evaluation 10.0 (26100)
````