.name "forking live"

	and  %0,%0,r2
start:
	fork %0
	live %42
	zjmp %:start
