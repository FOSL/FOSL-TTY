#include "tty.h"

namespace Lib
{
	namespace Tty
	{
		using namespace TTY;

		// TODO: IMPLEMENT BASED ON: http://www.termsys.demon.co.uk/vtansi.htm#print

		// GETTERS
		uint8_t Tty::device_code(void)
		{
		}
		DEVICE_STATUS Tty::device_status(void)
		{
		}
		CursorPosition Tty::cursor_position(void)
		{
		}
		// SETTERS
		void Tty::define_key(const char* key, const char* definition)
		{
		}
		void Tty::line_wrap(bool enable)
		{
			switch (enable)
			{
				case true:  printf(ESC"7h");
				case false: printf(ESC"7l");
			}
		}
		void Tty::cursor_position(CursorPosition new_cursor_position)
		{
		}

		// METHODS
		void Tty::reset_device(void)
		{
			printf(ESC"c");
		}
		void Tty::print_screen(void)
		{
		}
		void Tty::print_line(void)
		{
		}
		void Tty::shift_cursor(CURSOR::DIRECTION direction, uint16_t magnitude)
		{
		}
		void Tty::save_cursor(void)
		{
		} void Tty::save_cursor_and_attrs(void)
		{
		}
		void Tty::restore_cursor(void)
		{
		}
		void Tty::restore_cursor_and_attrs(void)
		{
		}
		void Tty::scroll(SCROLL::DIRECTION direction, uint16_t magnitude)
		{
		}

		// OPERATORS
		void Tty::operator()(TAB tab)
		{
		}
		void Tty::operator()(ERASE erase)
		{
			switch (erase)
			{
				case ERASE::TO_END_OF_LINE:
					printf(ESC"[K");
					break;
				case ERASE::FROM_START_OF_LINE:
					printf(ESC"[1K");
					break;
				case ERASE::CURRENT_LINE:
					printf(ESC"[2K");
					break;
				case ERASE::TO_TOP_OF_THE_SCREEN:
					printf(ESC"[J");
					break;
				case ERASE::TO_BOTTOM_OF_THE_SCREEN:
					printf(ESC"[1J");
					break;
				case ERASE::SCREEN:
					printf(ESC"[2J");
					break;
			}
		}
		void Tty::operator()(PRINT print)
		{
		}
	}
}
