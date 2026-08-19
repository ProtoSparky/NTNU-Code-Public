# ============================================
# Script: AKTIVERE_ELLER_DEAKTIVERE_GUEST_ACCOUNT/program.ps1
# Purpose: Aktiverer eller deaktiverer guest account for maskiner på AD
# Author: Kristupas Kaupas
# Date: 11-03-2026
# ============================================

<#
.SYNOPSIS
Aktiverer eller deaktiverer guest account for maskiner på en AD

.DESCRIPTION
Aktiverer eller deaktiverer guest account for alle maskiner som er på en AD server. Krever administrator tilgang

.PARAMETER guestAccountState
enable eller disable. Enable skrur på guest account. Disable skrur av guest account

.EXAMPLE
./program.ps1 -guestAccountState enable
Skrur på guest account

.EXAMPLE
./program.ps1 -guestAccountState disable
Skrur av guest account
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string] $guestAccountState
)
Import-Module ActiveDirectory

$adDoamin = "sec.core" #Domain name of AD

function setGuestState{
    param (
        [bool]$requestedGuestState
    )

    # Enabling or disabling guest account on AD
    if($requestedGuestState){Enable-ADAccount "Guest"}
    else{Disable-ADAccount "Guest"}

    # Checking if changes were actually saved
    if($requestedGuestState -ne (Get-ADUser -Server $adDoamin -Filter "Name -eq 'Guest'").Enabled){
        Write-Output("Failed to apply guest account changes!")
    }
}

# script parameter handling
if($guestAccountState.toLower() -eq "enable"){
    Write-Output("Trying to enable guest account..")
    setGuestState -requestedGuestState $true
}
elseif($guestAccountState.toLower() -eq "disable"){
    Write-Output("Trying to disable guest account..")
    setGuestState -requestedGuestState $false
}
else{Write-Output("Parameter not recognized. Syntax: guestAccountState [enable/disable]")}