.text
.global attackPos
.global canPlaceShip
.global canAttackPos
.global clearBoard
.global isShipSunken
.global placeShip
.global translate

# ---------------------------------------------------------------------------
# Suppose attackPos is called if pos hasn't been atacked before

# index to address
findAddress:  # start in %rbx, index in %rcx
  lea (%rbx, %rcx, 8), %rax
  ret

# &attackBoard[0] in %rdi, &myBoard[0] in %rsi, index in %rdx
attackPos:
  push %rdi
  push %rsi
  push %rdx

  # Get address of attackBoard position
  mov %rdi, %rbx  # attackBoard to %rbx
  mov %rdx, %rcx  # index to %rcx
  call findAddress
  mov %rax, %r8  # attackBoard position to %r8

  # Get address of myBoard position
  mov %rsi, %rbx  # myBoard to %rbx
  call findAddress
  mov %rax, %r9  # myBoard position to %r9

  pop %rdx
  pop %rsi
  pop %rdi

  mov (%r9), %rbx  # Check if there's a boat or not
  cmp $0, %rbx  # *r9 == 0 ?
  je miss
hit:
  mov %rbx, %rax
  mov $-1, %rbx
  mul %rbx  # Multiply value found by -1 (denotes hit)
  mov %rax, (%r8)  # register hit on both boards
  mov %rax, (%r9)
  jmp end
miss: 
  mov $-1, %rdx
  mov %rdx, (%r8)  # register miss on attackBoard
  mov %rdx, %rax  # return -1 if miss
end:
  ret

# ---------------------------------------------------------------------------
# %rdi attackBoard from player attacking, %rsi index
canAttackPos:
  mov	(%rdi, %rsi, 8), %rax
  cmp $0, %rax
  je success
  jmp failure

success:
  mov $1, %rax
  jmp end

failure:
  mov $0, %rax
  jmp end

# ---------------------------------------------------------------------------
translate:
# RDI(Row), RSI(Column)
  mov $7, %rax
  mul %rdi
  add %rsi, %rax
  ret

# ---------------------------------------------------------------------------
# myBoard in %rdi, %rsi ship's starting position, ship's size in %rdx
# placement direction in %rcx
canPlaceShip:
  cmp $0, %rsi # Lowest index in array
  jl placeFalse
  cmp $48, %rsi # Highest index in array
  jg placeFalse
  mov (%rdi, %rsi, 8), %r8
  cmp $0, %r8 
  jne placeFalse # If first spot is already taken, leave

  # Check if not in border
  mov $0, %r9 # Counter to check later on
  mov $0, %r10 # Counter to check later on

  # Find desired direction to check
  cmp $1, %rcx 
  je firstLeft
  cmp $2, %rcx
  je firstUp
  cmp $3, %rcx
  je firstRight
  jmp firstDown

firstLeft:
  mov $0, %r8 # Beginning point
  jmp firstCheck

firstUp:
  # If ship's starting position is less than 6 and direction is up
  cmp $6, %rsi 
  # It can't be placed
  jle placeFalse
  jmp firstCheckResult

firstRight:
  mov $6, %r8 # Beginning point
  jmp firstCheck

firstDown:
  # Index must be 42 <= index <= 48
  cmp $42, %rsi
  # If it is less than 42, there is no problem
  jl firstCheckResult
  # If ship's starting position is less than 48 and direction is down
  cmp $48, %rsi 
  # It can't be placed
  jle placeFalse
  jmp firstCheckResult

firstCheck:
  cmp %rsi, %r8
  je placeFalse
  inc %r9 # Add 1 to counter
  cmp $7, %r9 # If they are equal, move to next check
  je firstCheckResult
  jmp firstCheckDir # Finds direction and inputs correct one

firstCheckDir:
  add $7, %r8 # Add 7 to move row
  cmp $1, %rcx 
  je firstCheck
  cmp $3, %rcx
  je firstCheck
  sub $7, %r8 # Undo changes
  add $1, %r8 # Add 1 to move column
  je firstCheck # If not left or right, it is upwards or downwards

firstCheckResult:
   # If size is 2, all border cases have been checked
  cmp $2, %rdx
  je findAnotherShip
  # Counter to check later on
  mov $0, %r9
  # Find desired direction to check
  cmp $1, %rcx 
  je secondLeft
  cmp $2, %rcx
  je secondUp
  cmp $3, %rcx
  je secondRight 
  jmp secondDown

secondLeft:
  mov $1, %r8 # Beginning point
  jmp secondCheck

secondUp:
  # If ship's starting position is less than 13 and direction is up
  cmp $13, %rsi
  # It can't be placed
  jle placeFalse
  jmp secondCheckResult

secondRight:
  mov $5, %r8 # Beginning point
  jmp secondCheck

secondDown:
  # Index must be 35 <= index <= 41
  cmp $35, %rsi
  # If it is less than 35, there is no problem
  jl secondCheckResult
  # If ship's starting position is less than 41 and direction is down
  cmp $41, %rsi 
  # It can't be placed
  jle placeFalse
  jmp secondCheckResult

secondCheck:
  cmp %rsi, %r8
  je placeFalse
  inc %r9 # Add 1 to counter
  cmp $7, %r9 # If they are equal, move to next check
  je secondCheckResult
  jmp secondCheckDir # Finds direction and inputs correct one

secondCheckDir:
  add $7, %r8 # Add 7 to move row
  cmp $1, %rcx 
  je secondCheck
  cmp $3, %rcx
  je secondCheck
  sub $7, %r8 # Undo the direction
  inc %r8 # Add 1 to move column
  je secondCheck # If not left or right, it is upwards or downwards

secondCheckResult:
  cmp $3, %rdx # If size is 3, all border cases have been checked
  # je placeTrue
  je findAnotherShip
  # Counter to check later on
  mov $0, %r9
  # Find desired direction to check
  cmp $1, %rcx 
  je thirdLeft
  cmp $2, %rcx
  je thirdUp
  cmp $3, %rcx
  je thirdRight
  jmp thirdDown

thirdLeft:
  mov $2, %r8 # Beginning point
  jmp thirdCheck

thirdUp:
  # If ship's starting position is less than 20 and direction is up
  cmp $20, %rsi
  # It can't be placed
  jle placeFalse
  jmp findAnotherShip

thirdRight:
  mov $4, %r8 # Beginning point
  jmp thirdCheck

thirdDown:
  # Index must be 28 <= index <= 34
  cmp $28, %rsi
  # If it is less than 28, there is no problem
  jl findAnotherShip
  # If ship's starting position is less than 34 and direction is down
  cmp $34, %rsi 
  # It can't be placed
  jle placeFalse
  jmp findAnotherShip

thirdCheck:
  cmp %rsi, %r8
  je placeFalse
  inc %r9 # Add 1 to counter
  cmp $7, %r9 # If they are equal, move to next check
  je findAnotherShip # No more border cases to be checked after this
  jmp thirdCheckDir # Finds direction and inputs correct one

thirdCheckDir:
  add $7, %r8 # Add 7 to move row
  cmp $1, %rcx 
  je thirdCheck
  cmp $3, %rcx
  je thirdCheck
  sub $7, %r8 # Undo the direction
  inc %r8 # Add 1 to move column
  je thirdCheck # If not left or right, it is upwards or downwards

findAnotherShip:

  # jmp placeTrue
  mov (%rdi, %rsi, 8), %r8
  cmp $0, %r8 
  jne placeFalse # If spot is already taken, leave
  inc %r10 # Add 1 to counter
  cmp %r10, %rdx # If counter is equal to size, all positions have been checked
  je placeTrue
  jmp findShipDir

findShipDir:
  mov %rsi, %r8
  add $7, %rsi # Add 7 to move row
  cmp $4, %rcx # Downwards
  je findAnotherShip
  mov %r8, %rsi # Undo previous check
  sub $7, %rsi # Sub 7 to move row
  cmp $2, %rcx # Upwards
  je findAnotherShip
  mov %r8, %rsi # Undo previous check
  inc %rsi
  cmp $3, %rcx # Upwards
  je findAnotherShip
  mov %r8, %rsi # Undo previous check
  dec %rsi
  jmp findAnotherShip

placeTrue:
  mov $1, %rax
  ret

placeFalse:
  mov $0, %rax
  ret

# ---------------------------------------------------------------------------
# myBoard in %rdi, %rsi ship's starting position, ship's size in %rdx
# placement direction in %rcx, ship's value in %r8
isShipSunken:
  mov $0, %r10 # Set counter to 0

sunkLoop:
  mov (%rdi, %rsi, 8), %rax
  cmp %r8, %rax # If equal, can't be sunk'
  je sunkFalse
  inc %r10 # Add 1 to counter
  cmp %r10, %rdx # If counter is equal to size, all positions have been checked
  je sunkTrue
  jmp sunkDir

# Prepares correct direction to have 1 loop instead of several
sunkDir:
  dec %rsi # Decrease by 1 to move left
  cmp $1, %rcx  # Left 
  je sunkLoop
  inc %rsi # Undo previous
  sub $7, %rsi # Decrease 7 to move row upwards
  cmp $2, %rcx  # Up
  je sunkLoop
  add $7, %rsi # Undo previous
  inc %rsi # Increase by 1 to move right
  cmp $3, %rcx  # Right
  je sunkLoop
  dec %rsi # Undo previous
  add $7, %rsi # Add 7 to move row downwards
  jmp sunkLoop  # Down

sunkTrue:
  mov $1, %rax
  ret

sunkFalse:
  mov $0, %rax
  ret


# ---------------------------------------------------------------------------
# ship's value in %rdi, board address in %rsi, ship's size in %rdx,
# placement direction in %rcx, array index in %r8
placeShip:
placeFirstPosition:
  mov %rdi, (%rsi, %r8, 8) # Move ship's value to starting position
  dec %rdx # Use ship's size as counter
  cmp $1, %rcx
  je placeLeftwards
  cmp $2, %rcx
  je placeUpwards
  cmp $3, %rcx
  je placeRightwards
  jmp placeDownwards

placeLeftwards:
  sub $1, %r8 # Update index value
  mov %rdi, (%rsi, %r8, 8)  # Move ship's value to next position (one to the left)
  dec %rdx # Update counter
  test %rdx, %rdx  # If counter == 0, the ship is completely placed
  jg placeLeftwards
  jmp end

placeUpwards:
  sub $7, %r8  # One up = seven to the left
  mov %rdi, (%rsi, %r8, 8)
  dec %rdx
  test %rdx, %rdx
  jg placeUpwards
  jmp end

placeRightwards:
  add $1, %r8  # One to the right
  mov %rdi, (%rsi, %r8, 8)
  dec %rdx
  test %rdx, %rdx
  jg placeRightwards
  jmp end
  
placeDownwards:
  add $7, %r8  # One below = seven to the right
  mov %rdi, (%rsi, %r8, 8)
  dec %rdx
  test %rdx, %rdx
  jg placeDownwards
  jmp end

# ---------------------------------------------------------------------------
# Board address in %rdi
clearBoard:
  mov $0, %rbx
  mov $48, %rcx  # Clear positons from 48 to 0
clearPos:
  mov %rbx, (%rdi, %rcx, 8)  # Clear position
  dec %rcx
  cmp $0, %rcx
  jge clearPos
  jmp end
