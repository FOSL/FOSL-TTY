// SETTERS
template <typename ...arg_ts>
void base::set(arg_ts... args)
{
	printf("\033[");
	send_display_attributes(args...);
	printf("m");
}

// METHODS
inline void base::putchar(int c)
{
	putc(c, stream);
}
inline int base::getchar(void)
{
	return getc(stream);
}
inline void base::puts(char const*s)
{
	fputs(s, stream);
	putc('\n', stream);
}
inline char* base::gets(char *s, int size)
{
	return fgets(s, size, stream);
}
inline int base::printf(char const*format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stream, format, ap);
	va_end(ap);
}
inline int base::scanf(char const*format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stream, format, ap);
	va_end(ap);
}
// METHODS
template <typename arg_t, typename ...arg_ts>
void base::send_display_attributes(arg_t arg, arg_ts... args)
{
	printf("%u;", static_cast<uint8_t>(arg));
	send_display_attributes(args...);
}
template <typename arg_t>
void base::send_display_attributes(arg_t arg)
{
	printf("%u", static_cast<uint8_t>(arg));
}
