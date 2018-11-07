var addon = require('./build/Release/addon');
var Vector2 = addon.Vector2;


console.log("Check addScalar by passing 10, 200");
var vec2 = new Vector2(10, 200);
console.log( vec2.x );
console.log( vec2.y );

console.log("Check addScalar by passing 2.");
vec2.addScalar(2);
console.log( vec2.x );
console.log( vec2.y );

console.log("Check addScalar by passing no argument.");
vec2.addScalar();

console.log( vec2.x );
console.log( vec2.y );

console.log("Check multiplyScalar by passing 2.");
vec2.multiplyScalar(2);
console.log( vec2.x );
console.log( vec2.y );

console.log("Check addScalar by passing no argument.");
vec2.multiplyScalar();

console.log( vec2.x );
console.log( vec2.y );

console.log("Check add by passing vec2(4,5).");
var vec2_1 = new Vector2(4,5);
vec2.add(vec2_1);
console.log( vec2.x );
console.log( vec2.y );

console.log("Check add by passing undefined.");
vec2.add();
console.log( vec2.x );
console.log( vec2.y );