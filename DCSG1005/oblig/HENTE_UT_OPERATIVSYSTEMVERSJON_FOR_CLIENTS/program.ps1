# ============================================
# Script:  HENTE_UT_OPERATIVSYSTEMVERSJON_FOR_CLIENTST/program.ps1
# Purpose: Viser OS versjon for clients i en AD
# Author: Kristupas Kaupas
# Date: 12-03-2026
# ============================================
<#
.SYNOPSIS
Viser OS versjon for clients på en AD i en tabell

.DESCRIPTION
Viser OS versjon i tabell. Tar input for å vise de første eller siste clients i lista. Har søkefunksjon for å sjekke en spesifikk client

.PARAMETER head
Viser bare de første x antall clients

.PARAMETER tail
Viser bare de siste x antall clients

.PARAMETER name
Søke på spesifikk client. FEKS dc1, cl1 etc

.EXAMPLE
./program.ps1

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
DC1  Windows Server 2025 Standard Evaluation 10.0 (26100)
MGR  Windows 11 Enterprise Evaluation        10.0 (26100)
SRV1 Windows Server 2025 Standard Evaluation 10.0 (26100)
CL1  Windows 11 Enterprise Evaluation        10.0 (26100)

.EXAMPLE
./program.ps1 -head 2

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
DC1  Windows Server 2025 Standard Evaluation 10.0 (26100)
MGR  Windows 11 Enterprise Evaluation        10.0 (26100)

.EXAMPLE
./program.ps1 -tail 3

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
MGR  Windows 11 Enterprise Evaluation        10.0 (26100)
SRV1 Windows Server 2025 Standard Evaluation 10.0 (26100)
CL1  Windows 11 Enterprise Evaluation        10.0 (26100)

.EXAMPLE
/program.ps1 -name dc1

Name OperatingSystem                         OperatingSystemVersion
---- ---------------                         ----------------------
DC1  Windows Server 2025 Standard Evaluation 10.0 (26100)
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $false)]
    [int]$head,
    [Parameter(Mandatory = $false)]
    [int]$tail,
    [Parameter(Mandatory = $false)]
    [string]$name
)
Import-Module ActiveDirectory
$filter = "*" #Default filter to get all servers

#checks if name is not empty, and apply filter to search for specific name
if($name){
    $filter = "Name -eq '$name'"
}

#Gets all systems
$systems = Get-ADComputer -Filter $filter -Properties Name, OperatingSystem, OperatingSystemVersion | Select-Object Name, OperatingSystem, OperatingSystemVersion

#apply head
if($head -ne 0){
    $systems = $systems | Select-Object -First $head
}

#apply tail
if($tail -ne 0){
    $systems = $systems | Select-Object -Last $tail
}

Write-Output($systems | Format-Table -AutoSize)