.name "zork"
.comment "just a basic living prog"
		
lab1:	
	live %1
	zjmp %:lab1
	zjmp %:lab2
	live %3
lab2:
	live %14
