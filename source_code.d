var this := 7;
var that := 17.9;
var those := "anything";
var e;

var r := this is int;    //TRUE
var s := that is real;      //TRUE
var t := those is string;  //TRUE
var u := e is empty;        //TRUE

//var sas := empty;
//var syas := empty;
//print sas + syas;	//ERROR

print r;
print s;
print t;
print u;

var a := true and true;
var b := not true;
var c := false xor false;
var d := true or true;

print "if " , a , " then not " , b , " but " + " if " , c , " then " , d;