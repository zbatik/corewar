.name           "42"
.comment        "Just a basic Winner Program"

entree:
	live	%42		# entree
	ld	%0,r5,r10
	ld	%0,r5
	zjmp	%:bite

tird:	live	%42
	sti	r10,%:fin,r2
	sti	r10,%:fin,r3
	add	r4,r5,r4
	add	r3,r4,r3
	sub	r2,r4,r2
	zjmp	%:tirdow
	ld	%0,r11
	zjmp	%:tird
	zjmp	%:p1

fin:	live	%633
