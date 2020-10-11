var carDescription := {brand := "KIA", model := "Seltos", year := 2019};
carDescription := carDescription + {color := "red"};
carDescription.dob := "today";
print "This car is a ", carDescription.color, " ", carDescription.1, " ", carDescription.model, " made in ", carDescription.3;
print carDescription.dob;