#include <stdio.h>
int main(){
	int syscall_number = 1;
	int exit_code = 0;

	__asm__ (
		"movl %0, %%eax;"
		"movl %1, %%ebx;"
		"int $0x80;"
		:
		: "r"(syscall_number), "r"(exit_code)
		: "%eax", "%ebx"
	);
}