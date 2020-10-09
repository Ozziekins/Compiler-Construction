var this := 7;
var that := 17.9;
var those := "anything";
var e;

var r := this is real;    //TRUE
var s := that is real;      //TRUE
var t := those is string;  //TRUE
var u := e is empty;        //TRUE


print "t: ", t;
print "s: ", s;
print "r: ", r;
print "u: ", u;