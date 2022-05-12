/* Copyright (C) 2016 Jeremiah Orians
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

#include <errno.h>
#include <stddef.h>

char* strcpy(char* dest, char const* src)
{
	int i = 0;

	while (0 != src[i])
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = 0;

	return dest;
}


char* strncpy(char* dest, char const* src, size_t count)
{
	if(0 == count) return dest;
	size_t i = 0;
	while(0 != src[i])
	{
		dest[i] = src[i];
		i = i + 1;
		if(count == i) return dest;
	}

	while(i <= count)
	{
		dest[i] = 0;
		i = i + 1;
	}

	return dest;
}


char* strcat(char* dest, char const* src)
{
	int i = 0;
	int j = 0;
	while(0 != dest[i]) i = i + 1;
	while(0 != src[j])
	{
		dest[i] = src[j];
		i = i + 1;
		j = j + 1;
	}
	dest[i] = 0;
	return dest;
}


char* strncat(char* dest, char const* src, size_t count)
{
	size_t i = 0;
	size_t j = 0;
	while(0 != dest[i]) i = i + 1;
	while(0 != src[j])
	{
		if(count == j)
		{
			dest[i] = 0;
			return dest;
		}
		dest[i] = src[j];
		i = i + 1;
		j = j + 1;
	}
	dest[i] = 0;
	return dest;
}


size_t strlen(char const* str )
{
	size_t i = 0;
	while(0 != str[i]) i = i + 1;
	return i;
}


size_t strnlen_s(char const* str, size_t strsz )
{
	size_t i = 0;
	while(0 != str[i])
	{
		if(strsz == i) return i;
		i = i + 1;
	}
	return i;
}


int strcmp(char const* lhs, char const* rhs )
{
	int i = 0;
	while(0 != lhs[i])
	{
		if(lhs[i] != rhs[i]) return lhs[i] - rhs[i];
		i = i + 1;
	}

	return lhs[i] - rhs[i];
}


int strncmp(char const* lhs, char const* rhs, size_t count)
{
	size_t i = 0;
	while(count > i)
	{
		if(0 == lhs[i]) break;
		if(lhs[i] != rhs[i]) return lhs[i] - rhs[i];
		i = i + 1;
	}

	return 0;
}


char* strchr(char const* str, int ch)
{
	char* p = str;
	while(ch != p[0])
	{
		if(0 == p[0]) return NULL;
		p = p + 1;
	}
	if(0 == p[0]) return NULL;
	return p;
}


char* strrchr(char const* str, int ch)
{
	char* p = str;
	int i = 0;
	while(0 != p[i]) i = i + 1;
	while(ch != p[i])
	{
		if(0 == i) return NULL;
		i = i - 1;
	}
	return (p + i);
}


size_t strspn(char const* dest, char const* src)
{
	if(0 == dest[0]) return 0;
	int i = 0;
	while(NULL != strchr(src, dest[i])) i = i + 1;
	return i;
}


size_t strcspn(char const* dest, char const* src)
{
	int i = 0;
	while(NULL == strchr(src, dest[i])) i = i + 1;
	return i;
}


char* strpbrk(char const* dest, char const* breakset)
{
	char* p = dest;
	char* s;
	while(0 != p[0])
	{
		s = strchr(breakset, p[0]);
		if(NULL != s) return strchr(p,  s[0]);
		p = p + 1;
	}
	return p;
}


void* memset(void* dest, int ch, size_t count)
{
	if(NULL == dest) return dest;
	size_t i = 0;
	char* s = dest;
	while(i < count)
	{
		s[i] = ch;
		i = i + 1;
	}
	return dest;
}


void* memcpy(void* dest, void const* src, size_t count)
{
	if(NULL == dest) return dest;
	if(NULL == src) return NULL;

	char* s1 = dest;
	char const* s2 = src;
	size_t i = 0;
	while(i < count)
	{
		s1[i] = s2[i];
		i = i + 1;
	}
	return dest;
}

void* memmove(void* dest, void const* src, size_t count)
{
	if (dest < src) return memcpy (dest, src, count);
	char *p = dest;
	char const *q = src;
	count = count - 1;
	while (count >= 0)
	{
		p[count] = q[count];
		count = count - 1;
	}
	return dest;
}


int memcmp(void const* lhs, void const* rhs, size_t count)
{
	if(0 == count) return 0;
	size_t i = 0;
	char const* s1 = lhs;
	char const* s2 = rhs;
	while(s1[i] == s2[i])
	{
		i = i + 1;
		if(count == i) return count;
	}
	return (s1[i] - s2[i]);
}


char *strerror(int errnum)
{
	switch (errnum) {
	case E2BIG:		return "argument list too long";
	case EACCES:		return "permission denied";
	case EADDRINUSE:	return "address in use";
	case EADDRNOTAVAIL:	return "address not available";
	case EAFNOSUPPORT:	return "address family not supported";
	case EAGAIN:		return "resource unavailable";
	case EALREADY:		return "connection already in progress";
	case EBADF:		return "bad file descriptor";
	case EBADMSG:		return "bad message";
	case EBUSY:		return "device or resource busy";
	case ECHILD:		return "no child processes";
	case ECONNABORTED:	return "connection aborted";
	case ECONNREFUSED:	return "connection refused";
	case ECONNRESET:	return "connection reset";
	case EDEADLK:		return "resource deadlock";
	case EDESTADDRREQ:	return "destination address required";
	case EDOM:		return "argument out of function's domain";
	case EEXIST:		return "file exists";
	case EFAULT:		return "bad address";
	case EFBIG:		return "file too big";
	case EHOSTUNREACH:	return "host unreachable";
	case EIDRM:		return "identifier removed";
	case EILSEQ:		return "illegal byte sequence";
	case EINPROGRESS:	return "operation in progress";
	case EINTR:		return "function interrupted";
	case EINVAL:		return "invalid argument";
	case EIO:		return "i/o error";
	case EISCONN:		return "socket connected";
	case EISDIR:		return "is a directory";
	case ELOOP:		return "too many levels of symbolic links";
	case EMFILE:		return "fd number too large";
	case EMLINK:		return "too many links";
	case EMSGSIZE:		return "message too big";
	case ENAMETOOLONG:	return "filename too long";
	case ENETDOWN:		return "network down";
	case ENETRESET:		return "network aborted connection";
	case ENETUNREACH:	return "network unreachable";
	case ENFILE:		return "too many open files";
	case ENOBUFS:		return "no buffer space";
	case ENODEV:		return "no such device";
	case ENOENT:		return "no such file";
	case ENOEXEC:		return "exec format error";
	case ENOLCK:		return "no lock available";
	case ENOMEM:		return "out of memory";
	case ENOMSG:		return "no message of the desired type";
	case ENOPROTOOPT:	return "protocol not available";
	case ENOSPC:		return "no space on device";
	case ENOSYS:		return "unsupported functionality";
	case ENOTCONN:		return "socket not connected";
	case ENOTDIR:		return "not a directory";
	case ENOTEMPTY:		return "directory not empty";
	case ENOTRECOVERABLE:	return "unrecoverable state";
	case ENOTSOCK:		return "not a socket";
	case ENOTSUP:		return "usupported functionality";
	case ENOTTY:		return "bad i/o control operation";
	case ENXIO:		return "no such device or address";
	case EOVERFLOW:		return "value too large for type";
	case EOWNERDEAD:	return "previous owner died";
	case EPERM:		return "not permitted";
	case EPROTO:		return "protocol error";
	case EPROTONOSUPPORT:	return "protocol not supported";
	case EPROTOTYPE:	return "wrong protocol type for socket";
	case ERANGE:		return "result too big";
	case EROFS:		return "read-only file system";
	case ESPIPE:		return "tried to seek on pipe";
	case ESRCH:		return "no such address";
	case ETIMEDOUT:		return "connection timed out";
	case ETXTBSY:		return "text file busy";
	case EXDEV:		return "cross-device link";
	default:
		    errno = EINVAL;
		    return "unknown error";
	}
}
