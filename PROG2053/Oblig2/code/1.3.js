/*
let total = 5;
for (let j = 3; j <= 8; j++) {
	if (j % 2 === 0) {
		total += j;
	} 
	else {
		total *= j;
	}
}
rewrite using while loop
*/

let total = 5;
let j = 3;
while(j <= 8){
    if (j % 2 === 0) {
		total += j;
	} 
	else {
		total *= j;
	}
    j ++ ; //increment j as this is no longer a for loop
}