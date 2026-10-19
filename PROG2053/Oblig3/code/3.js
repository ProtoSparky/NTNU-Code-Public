function main(){
    sendCampaign("Atumn Sale",generateRaport); 
}

function sendCampaign(campaignName,callback){
    console.log(`Initiating transmission sequence for ${campaignName}...`); 
    //3s timeout
    setTimeout(()=>{
        console.log("Emails delivered successfully to subscribers!"); 
        callback(); ///runs callback
    },3000)  

}
function generateRaport(){
    console.log("Performance analytics report compiled and updated on dashboard.");
}