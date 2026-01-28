$a = "test"
$a.GetType().FullName

$b = Get-Item "$PSHOME\powershell.exe"
$b.GetType().FullName

$c = @("abc","def")
$c += "ghi"
$c


$d = @{
    "value1"= "1234";
    "value2" = "5678"
}

$e = @{
    "frodeh" = "Frode Haug";
    "kelly" = "Jia-Chun Lin";
    "erik" = "Erik Hjemlås"; 
}

$str = "User frodeh has a real name $($e["frodeh"]) "

# nslookup.exe ftp.uninett.no | Get-Member      Legacy way of doing things

(Resolve-DnsName ftp.uninett.no).Ip4Address


(Resolve-DnsName ftp.uninett.no)| Select-Object -Property * 



# Creating reduced objects
Write-Output mysil > ./abc.txt

# show all properties
#Get-ChildItem ./abc.txt | Get-Member

# reduced object
# Get-ChildItem ./abc.txt | Select-Object -Property Name, LastWriteTime | Get-Member 


# Get-Process | Select-Object -First 5 


Get-ChildItem | Select-Object Name, Directory, @{
    Name="Owner"; Expression={(Get-ACL $_.FullName).Owner}
}, CreationTime, LastAccessTime | Format-Table

