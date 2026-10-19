function main(){
    getFlightInfo(); 
}
function getFlightInfo(){
    const urlString = "https://fly.com?name=norwegian&passenger=60";
    URLSearchParams(urlString.split("?")[1].split("&"));
}
function URLSearchParams(string){
    for(let i = 0; i < string.length; i++){
        let currentValue = string[i].split("=");
        console.log("Key:" + currentValue[0]);
        console.log("Value:"+currentValue[1]); 
    }
}