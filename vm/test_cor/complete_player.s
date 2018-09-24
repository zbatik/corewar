add r1,r2,r3
aff r1
and r1,r2,r3	# RRR
and r1,42,r3	# RIR
and %10,r2,r3	# DRR
and 11,12,r3	# IIR
and 13,r2,r3	# IRR
and %14,15,r3	# DIR
live %1
fork %1
live %1
ld %5, r1   # DR
ld 6, r2    # ID
ldi r1,r2,r3    # RRR
ldi %10,r2,r3   # DRR
live %1
ldi 11,r2,r3    # IRR
ldi r1,%12,r3   # RDR
ldi %13,%14,r3  # DDR
ldi 14,%15,r3   # IDR
live %1
lfork %10
live %42
lld	%50, r1 #DR
lld 50, r1 #IR
lldi r1,%42,r3	# RDR
lldi %42,%43,r3	# DDR
lldi 16,%17,r3	# IDR
#lldi r1,18,r3	# RIR
#lldi %42,43,r3	# DIR
#lldi 16,17,r3	# IIR
or r1,r2,r3	    # RRR
or r1,42,r3	    # RIR
or %10,r2,r3	# IRR
or 11,12,r3	    # IIR
or %13,r2,r3	# DRR
or %14,15,r3	# DIR
st r1, 7
live %1
st r2, r3
sti r1,r2,r3    # RRR
sti r1,%10,r3   # RDR
sti r1,11,r3    # RIR
sti r1,r2,%12   # RRD
live %1
sti r1,%13,%14  # RDD
sti r1,15,%15   # RID
sub r1,r2,r3
xor r1,r2,r3	# RRR
xor r1,42,r3	# RIR
xor %10,r2,r3	# IRR
xor 11,12,r3	# IIR
xor %13,r2,r3	# DRR
xor %14,15,r3	# DIR
zjmp %0
