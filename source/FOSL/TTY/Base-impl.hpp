template <typename ... Args>
Base& Base::operator()(Args ... args)
{
	printf(ESC"[");
	send_display_attributes(args ...);
	printf("m");

	return *this;
}

inline void Base::putchar(int c)
{
	putc(c, stream);
}
inline int Base::getchar(void)
{
	return getc(stream);
}
inline void Base::puts(const char* s)
{
	fputs(s, stream);
	putc('\n', stream);
}
inline char* Base::gets(char* s, int size)
{
	return fgets(s, size, stream);
}
inline int Base::printf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stream, format, ap);
	va_end(ap);
}
inline int Base::scanf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stream, format, ap);
	va_end(ap);
}

template <typename Arg, typename ... Args>
void Base::send_display_attributes(Arg arg, Args ... args)
{
	printf("%u;", static_cast<uint8_t>(arg));
	send_display_attributes(args ...);
}
template <typename Arg>
void Base::send_display_attributes(Arg arg)
{
	printf("%u", static_cast<uint8_t>(arg));
}
