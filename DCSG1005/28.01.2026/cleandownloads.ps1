# ============================================
# Skript: cleandownloads.ps1
# Formål: Rydder opp alle packet tracer filer i downloads mappen
# Forfatter: Kristupas Kaupas
# Dato: 2026-01-28
# ============================================

<#
.SYNOPSIS
Rydder opp alle packet tracer filer i downloads mappen

.DESCRIPTION
Søker rekursift gjennom downloads mappen etter .pka filer, og flytter det til "PacketTracerProjects" eller bruker-spesifisert mappe

.PARAMETER noLogs
Switch for å generere log fil. Default er true

.PARAMETER copyLocation
Navn på mappen packet tracer filer flyttes til. Default er "PacketTracerProjects"

.EXAMPLE
.\cleandownloads.ps1
flytter alle .pka filer til "PacketTracerProjects" og genererer en log fil i samme mappe

.EXAMPLE
.\cleandownloads.ps1 -noLogs -copyLocation "test"
Lager ingen logs. Flytter til en mappe "test" i downloads
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $false)]
    [switch]$noLogs,
    [Parameter(Mandatory = $false)]
    [ValidateNotNullOrEmpty()]
    [string]$copyLocation = "PacketTracerProjects"
)
$downloads = Join-Path $HOME "Downloads"
$packetTracerDir = Join-Path $downloads $copyLocation

#create dir if does not exist
New-Item -ItemType Directory -Path $packetTracerDir -Force | Out-Null

#Copy-item $downloads* $packetTracerDir -Include *.pka
Get-ChildItem -Path $downloads -Filter *.pka | Move-Item -Destination $packetTracerDir

if(-not $noLogs){
    $logPath = Join-Path $packetTracerDir "logs.txt"
    "Last run at $(Get-Date)" | Set-Content $logPath
}
