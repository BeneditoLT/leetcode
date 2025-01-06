

function search(nums,target){
    let left = 0;
    let right = nums.length -1;

    while(left <= right){
        const middle = Math.floor(left + (right -left)/ 2);

        if(nums[middle] === target){
            return middle;

        }else if(nums[middle] < target){
            left = middle +1;


        }else {
            right = middle -1;
        }
    }
    return -1;
}


//Codigo Principal


const nums = [1,2,3,4,5,6,7,8,9,10,11];
const target = 13;

const result = search(nums,target);


if (result !== -1  ){
    console.log(`Target ${target} encontrado `);

}else{
    console.log(`Target ${target} não encontrado`)
}