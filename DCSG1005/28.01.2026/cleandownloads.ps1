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

.PARAMETER makeLogs
Boolean for å generere log fil. Default er true

.PARAMETER copyLocation
Navn på mappen packet tracer filer flyttes til. Default er "PacketTracerProjects"

.EXAMPLE
.\cleandownloads.ps1
flytter alle .pka filer til "PacketTracerProjects" og genererer en log fil i samme mappe

.EXAMPLE
.\cleandownloads.ps1 -makeLogs $false -copyLocation "test"
Lager ingen logs. Flytter til en mappe "test" i downloads
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $false)]
    [boolean]$makeLogs = $true,
    [Parameter(Mandatory = $false)]
    [ValidateNotNullOrEmpty()]
    [string]$copyLocation = "PacketTracerProjects"
)
$downloads = "$($HOME)\Downloads\"
$packetTracerDir = "$($downloads)$($copyLocation)\"

#create dir if does not exist
if(-Not (Test-Path $packetTracerDir)){
    New-Item -Path $packetTracerDir -ItemType Directory
}

#Copy-item $downloads* $packetTracerDir -Include *.pka
Get-ChildItem -Path $downloads -Filter *.pka | Move-Item -Destination $packetTracerDir

if($makeLogs){
    $value = "Last copy run at $(Get-Date)"
    if(-Not (Test-Path "$($packetTracerDir)/logs.txt")){
        new-Item -Path $packetTracerDir -Name "logs.txt" -value $value | Out-Null
    }
    else{
        set-Content -Path "$($packetTracerDir)/logs.txt" -value $value | Out-Null
    }

}
