function main(){
    getBookingInfo();
}
function getBookingInfo(){
    const url = "https://travel.com?price=1000&day=Wednesday";
    const getRequests = url.split("?")[1].split("&")
    for(let i = 0; i < getRequests.length; i++){
        let currentValue = getRequests[i].split("=");
        console.log("Key:" + currentValue[0]);
        console.log("Value:"+currentValue[1]); 
    }


}