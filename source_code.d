var testArray := [1];
var weirdStruct := {testArray};

var test := 1;
weirdStruct := weirdStruct + {test} ;// Now it should be like this { Array, Array size }

var i := (5-4);
while ( i < 10/2 ) loop //Will go from 1 to 4 (5 not included) 
     weirdStruct.1 := weirdStruct.1 + weirdStruct.1;
     weirdStruct.2 := weirdStruct.2 + 1;
     
     i := i + 1;
end 
     
print "Array is ", weirdStruct.1, " While size is ", weirdStruct.2; // Allow printing of arrays??? 
     
