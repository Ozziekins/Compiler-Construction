var summation := func (N) is
	var counter := 1;
	var result := 0;
	while counter <= N loop
		result := result + counter;
		counter := counter + 1;
		end
return result;
end;
 
print summation(5); //15