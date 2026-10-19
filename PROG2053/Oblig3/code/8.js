function main(){
    applyUpgrade("Premium-User-Alpha", 4); 
}
async function getLoyaltyDiscount(yearsActive){
    if(yearsActive > 2){
        return 15;
    }
    else{
        return 0;
    }
}
async function applyUpgrade(accountName, yearsActive){
    console.log(`Starting upgrade process for ${accountName}...`); 
    const customerDiscount = await getLoyaltyDiscount(yearsActive);
    const baseCharge = 50;
    console.log(`Account ${accountName}'s processed. Final balance due: $${baseCharge - customerDiscount}`);
}