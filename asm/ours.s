.name "ours"
.comment "fbjaf"

entree: live	%42
fork	%:tir
	ld	%0,r5
	zjmp	%:tir

tir:	sti	r1,%:tirf,%1
	ld	%2304,r10
	ld	%1,r5
	ld	%0,r11

	ld	%4,r3
tirf:	live	%42
	fork	%:tir
	live	%742
	sub	r3,r5,r3
	zjmp	%:entree
	ld	%0,r11
	fork	%:tir
	live	%42
	sti	r10,%-510,%0
	sti	r10,%-404,%0
	sti	r10,%-303,%0
	sti	r10,%-202,%0
	ld	%0,r11
	zjmp	%:tirf

