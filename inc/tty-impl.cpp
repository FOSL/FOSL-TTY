// SETTERS
template <typename ... Args>
void Tty::operator()(Args ... args)
{
	printf(ESC"[");
	send_display_attributes(args ...);
	printf("m");
}

// METHODS
inline void Tty::putchar(int c)
{
	putc(c, stdout);
}
inline int Tty::getchar(void)
{
	return getc(stdout);
}
inline void Tty::puts(const char* s)
{
	fputs(s, stdout);
	putc('\n', stdout);
}
inline char* Tty::gets(char* s, int size)
{
	return fgets(s, size, stdout);
}
inline int Tty::printf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stdout, format, ap);
	va_end(ap);
}
inline int Tty::scanf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stdout, format, ap);
	va_end(ap);
}

template <typename Arg, typename ... Args>
void Tty::send_display_attributes(Arg arg, Args ... args)
{
	printf("%u;", static_cast<uint8_t>(arg));
	send_display_attributes(args ...);
}
template <typename Arg>
void Tty::send_display_attributes(Arg arg)
{
	printf("%u", static_cast<uint8_t>(arg));
}
