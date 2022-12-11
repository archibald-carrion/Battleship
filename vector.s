#
#  CI-0118
#  Grupo 2 (Fco. Arroyo)
#
#   Modulos en ensamblador para la clase Vector
#
#   Compile: g++ -g testVector.cc Vectoc.cc vector.s -o testVector.out
#

.text
.global init			# Vector::Vector( int size )
.global destroy		# Vector::~Vector()
.global allset			# Vector::allSet( long value )
.global eleset			# Vector::set( int position, long value )
.global eleget			# Vector::get( int position )

# ---------------------------------------------------------------------------
init:				# For class constructor
	shl	$3, %rdi		# use 64 bits words
	push	%rdi			# malloc need its parameter to be pushed on stack
	xor	%rax, %rax	# set AX to zero
	call	malloc		# AX will have a pointer to new allocated space
	pop	%rdi
	ret

# ---------------------------------------------------------------------------
destroy:				# For class destructor
	push	%rdi
	call	free
	pop	%rdi
	ret

# ---------------------------------------------------------------------------
allset:				# For method "allSet" DI address, SI size, DX value
	mov	%rsi, %rcx
	xor	%rsi, %rsi
next:
	mov	%rdx, ( %rdi, %rsi, 8 )
	inc	%rsi
	loop	next
	ret

# ---------------------------------------------------------------------------
eleset:	   			# For "set" method: DI address, SI position, DX value
	mov	%rdx, (%rdi, %rsi, 8)
	ret

# ---------------------------------------------------------------------------
eleget:				# For "get" method: DI address, SI position
	mov	( %rdi, %rsi, 8 ), %rax
	ret

.data
