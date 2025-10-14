section .bss
n resq 1
sum resq 1
target resq 1
i resq 1
first resq 1000        ; first set array
second resq 1000       ; second set array
first_cnt resq 1
second_cnt resq 1

section .data
yes db "YES",10,0
no db "NO",10,0
fmt db "%lld",0
space db " ",0
nl db 10,0

section .text
global main
extern printf, scanf

main:
    ; read n
    mov rdi, fmt
    lea rsi, [n]
    xor rax, rax
    call scanf

    ; sum = n*(n+1)/2
    mov rax, [n]
    mov rbx, rax
    add rbx, 1
    mul rbx            ; rax = n*(n+1)
    mov rbx, 2
    div rbx            ; rax = sum
    mov [sum], rax

    ; if sum % 2 == 1 -> NO
    test rax, 1
    jnz .print_no

    ; target = sum/2
    mov rax, [sum]
    mov rbx, 2
    div rbx
    mov [target], rax

    ; initialize counters
    mov qword [first_cnt], 0
    mov qword [second_cnt], 0

    ; i = n
    mov rax, [n]
    mov [i], rax

.loop:
    mov rax, [i]
    cmp rax, 0
    jle .done_loop

    mov rbx, [target]
    cmp rax, rbx
    jg .add_second

    ; add to first
    mov rcx, [first_cnt]
    mov [first+rcx*8], rax
    add qword [first_cnt], 1
    sub [target], rax
    jmp .next_i

.add_second:
    mov rcx, [second_cnt]
    mov [second+rcx*8], rax
    add qword [second_cnt], 1

.next_i:
    sub qword [i], 1
    jmp .loop

.done_loop:
    ; print YES
    mov rdi, yes
    xor rax, rax
    call printf

    ; print first set
    mov rax, [first_cnt]
    mov rsi, rax
    mov rdi, fmt
    mov rax, 0
    call printf

    ; print first elements
    mov rcx, 0
.print_first_loop:
    cmp rcx, [first_cnt]
    jge .print_second
    mov rax, [first+rcx*8]
    mov rdi, fmt
    mov rsi, rax
    xor rax, rax
    call printf
    mov rdi, space
    xor rax, rax
    call printf
    inc rcx
    jmp .print_first_loop

.print_second:
    mov rax, [second_cnt]
    mov rsi, rax
    mov rdi, fmt
    xor rax, rax
    call printf

    ; print second elements
    mov rcx, 0
.print_second_loop:
    cmp rcx, [second_cnt]
    jge .exit
    mov rax, [second+rcx*8]
    mov rdi, fmt
    mov rsi, rax
    xor rax, rax
    call printf
    mov rdi, space
    xor rax, rax
    call printf
    inc rcx
    jmp .print_second_loop

.print_no:
    mov rdi, no
    xor rax, rax
    call printf

.exit:
    ret
