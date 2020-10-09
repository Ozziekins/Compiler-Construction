<<<<<<< HEAD
var this := {name := "1", age := 1, 1.1, is_married := true};
=======
var factorial := func(n) is 
    if n = 0 then		// Brackets are omitted intentionally
    	return 1;
    else
        return n * factorial(n - 1);
    end
end;
var lambdafunc := func(x) => x/1.4;

print lambdafunc(4);

print  factorial(4), " The output should be 24/1.4 ~= 17,142";
>>>>>>> f1ebe1bf9b0cf288fda3513e382dc4f401d923e8
