## First case ##
```
var x := 15; 
var y := 36; 

print "The max var from x and y is "; // 36 

if x > y then 
    print x; 
else 
    print y; 
end 

var mult := x * y; 

print "x * y = "; 
print mult; //540
```
## Second case ##
```
var array[20] := [];
var initial_value = -10;

for i in array loop
    array[i] = initial_value + 1;
end

for i in array loop
    if array[i] > 0 then
        print array[i]
    end 
end
```
## Third case ##
```
var something := 1;
something := increment(something) is
   return something + 1;
end
print something;
```
## Fourth case ##
```
var x := 0;
var y := -1;
var z:= 4;

if x > y and x > z then
    if y > z then
        print z;
    else
        print y;
    end
else
    if y > x and y > z then
        if x > z then
            print z;
        else 
            print x;
        end
    else 
        if z > x and z > y then
            if x > y then 
                print y;
            else 
                print x;
            end
        end
    end
end 
```
## Fifth case ##
```
var c;
c := do_math(10, 5, 7) is 
  var count := 0;
    while x >= y loop
        if y > z then
            y := y + 1;
        else
            z := z - 1;
        end
    count := count + 1;
    end
    return count;
 end
 print c;
```
