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