function main(){
    processItem("Laptop"); 
}
async function checkStockLevel(){
    return 45;
}
async function isWarehouseOpen(){
    return true;
}
async function processItem(itemName){
    if(! await isWarehouseOpen()){
        console.log("Warehosue closed. Aborting!!");
    }
    else{
        console.log("Warehouse open.");
        console.log(`${await checkStockLevel() + 10} item/s in stock for ${itemName}`); 
    }
}