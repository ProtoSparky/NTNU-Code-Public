function main(){
    const validateCoupon = new Promise((resolve, reject)=>{
        const shoppingCart = {
            couponCode:"SAVE15",
            codeExpired:false,
            basePrice:200
        }
        const correctCoupon = "SAVE15";

        if(shoppingCart.couponCode != "SAVE15"){
            //wrong coupon
            reject("Invalid coupon code!"); 
        }

        if(shoppingCart.couponCode == correctCoupon && shoppingCart.codeExpired){
            //correct coupon, code expired
            reject("Coupon code expired!"); 
        }

        if(shoppingCart.couponCode == correctCoupon && !shoppingCart.codeExpired){
            //correct coupon, not expired
            const savedPrice = shoppingCart.basePrice * 0.15;
            resolve(`Success! Saved $${savedPrice}. Your adjusted checkout total is $${shoppingCart.basePrice - savedPrice}`); 
        }
    });

    validateCoupon.then(result=>{
        console.log(result);
    });
    validateCoupon.catch(error=>{
        console.log(error);
    });
    validateCoupon.finally(()=>{
        console.log("Session sync complete.");
    })
}