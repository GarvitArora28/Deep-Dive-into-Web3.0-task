const sha256 = require('crypto-js/sha256.js');
const { performance } = require('perf_hooks');
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Enter the string please!\n", (str) => {
    var nonce = '0';
    var starttime = performance.now();
    while (sha256(str + nonce).toString().substring(0, 5) != "00000") {
        nonce++;
    }
    var endtime = performance.now();
    console.log("The required nonce is " + nonce);
    console.log("The final string is " + str + nonce);
    console.log('The hash of the string + num is ' + sha256(str + nonce));
    console.log("Total time: " + (endtime - starttime)+" in miliseconds.");
});