.name "st test"

start:
	st r1,r2		#copy player number to r2
	st r2,42		#copy player number to (pc + 10) % IDX_MOD
	st r2,532		#copy player number to (pc + 516) % IDX_MOD (ie pc + 16)
	st r3,:start	#copy 0 over the first instruction
