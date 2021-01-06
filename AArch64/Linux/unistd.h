/* Copyright (C) 2016 Jeremiah Orians
 * Copyright (C) 2020 deesix <deesix@tuta.io>
 * This file is part of M2-Planet.
 *
 * M2-Planet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * M2-Planet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with M2-Planet.  If not, see <http://www.gnu.org/licenses/>.
 */

int access(char* pathname, int mode)
{
	asm("SET_X0_FROM_BP" "SUB_X0_16" "DEREF_X0"
	    "SET_X2_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X1_FROM_X0"
	    "SET_X0_TO_0"
	    "SET_X3_FROM_X0"
	    "SET_X0_TO_FCNTL_H_AT_FDCWD"
	    "SET_X8_TO_SYS_FACCESSAT"
	    "SYSCALL");
}

int chdir(char* path)
{
	asm("SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_CHDIR"
	    "SYSCALL");
}

int fchdir(int fd)
{
	asm("SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_FCHDIR"
	    "SYSCALL");
}

void exit(int value)
{
	asm("SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_EXIT"
	    "SYSCALL");
}

void _exit(int value)
{
	exit(value);
}

int fork()
{
	asm("SET_X0_TO_0"
	    "SET_X1_FROM_X0"
	    "SET_X2_FROM_X0"
	    "SET_X3_FROM_X0"
	    "SET_X4_FROM_X0"
	    "SET_X5_FROM_X0"
	    "SET_X6_FROM_X0"
	    "SET_X0_TO_17"
	    "SET_X8_TO_SYS_CLONE"
	    "SYSCALL");
}

int waitpid(int pid, int* status_ptr, int options)
{
	asm("SET_X0_TO_MINUS_1"
	    "SET_X3_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_24" "DEREF_X0"
	    "SET_X2_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_16" "DEREF_X0"
	    "SET_X1_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_WAIT4"
	    "SYSCALL");
}

int execve(char* file_name, char** argv, char** envp)
{
	asm(
	    "SET_X0_FROM_BP" "SUB_X0_24" "DEREF_X0"
	    "SET_X2_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_16" "DEREF_X0"
	    "SET_X1_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_EXECVE"
	    "SYSCALL");
}

int _getcwd(char* buf, size_t size)
{
	asm("SET_X0_FROM_BP" "SUB_X0_16" "DEREF_X0"
	    "SET_X1_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_GETCWD"
	    "SYSCALL");
}

int brk(void *addr)
{
	asm("SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_BRK"
	    "SYSCALL");
}

int chmod(char *pathname, int mode)
{
	asm("SET_X0_FROM_BP" "SUB_X0_16" "DEREF_X0"
	    "SET_X2_FROM_X0"
	    "SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X1_FROM_X0"
	    "SET_X0_TO_0"
	    "SET_X3_FROM_X0"
	    "SET_X0_TO_FCNTL_H_AT_FDCWD"
	    "SET_X8_TO_SYS_FCHMODAT"
	    "SYSCALL");
}

struct utsname
{
	char sysname[65];    /* Operating system name (e.g., "Linux") */
	char nodename[65];   /* Name within "some implementation-defined network" */
	char release[65];    /* Operating system release (e.g., "2.6.28") */
	char version[65];    /* Operating system version */
	char machine[65];    /* Hardware identifier */
};

int uname(struct utsname* unameData)
{
	asm("SET_X0_FROM_BP" "SUB_X0_8" "DEREF_X0"
	    "SET_X8_TO_SYS_UNAME"
	    "SYSCALL");
}