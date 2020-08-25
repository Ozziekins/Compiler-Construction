var yearOfBirth := 1998;

var adult := yearOfBirth <= 2002;
print adult;       // true

var minor := yearOfBirth > 2002;
print minor;       // false

var PI := 3.14;
var testReal := 2;
var isPi := testReal = PI;
var isNotPi := testReal /= PI;
print isPi, isNotPi;        //false true