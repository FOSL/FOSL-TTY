#include "FOSL/TTY/Base.hpp"

namespace FOSL
{
	namespace TTY
	{
		// TODO: IMPLEMENT BASED ON: http://www.termsys.demon.co.uk/vtansi.htm#print

		Base::Base(FILE* initial_stream)
			: stream(initial_stream)
		{
		}

		uint8_t Base::get_device_code(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
			return 0;
		}
		DEVICE_STATUS Base::get_device_status(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
			return DEVICE_STATUS::OK;
		}
		CursorPosition Base::get_cursor_position(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
			return CursorPosition { 0, 0 };
		}

		void Base::set_line_wrap(bool enable)
		{
			switch (enable)
			{
				case true:  printf("\0337h");
				case false: printf("\0337l");
			}
		}
		void Base::set_cursor_position(CursorPosition cursor_position)
		{
			printf("\033[%u;%uf", cursor_position.y, cursor_position.x);
		}
		void Base::set_cursor_position(uint16_t x, uint16_t y)
		{
			printf("\033[%u;%uf", y, x);
		}

		void Base::reset_device(void)
		{
			printf("\033c");
		}
		void Base::print_screen(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void Base::print_line(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void Base::shift_cursor_position(CURSOR::DIRECTION direction, uint16_t magnitude)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void Base::save_cursor_position(void)
		{
			printf("\033[s");
		}
		void Base::save_cursor_and_attrs(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void Base::restore_cursor_position(void)
		{
			printf("\033[u");
		}
		void Base::restore_cursor_and_attrs(void)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void Base::define_key(const char* key, const char* definition)
		{
			assert(false && "THIS METHOD IS YET TO BE IMPLEMENTED!");
		}

		Base& Base::operator()(TAB tab)
		{
			return *this;
		}
		Base& Base::operator()(ERASE erase)
		{
			switch (erase)
			{
				case ERASE::TO_END_OF_LINE:
					printf("\033[K");
					break;
				case ERASE::FROM_START_OF_LINE:
					printf("\033[1K");
					break;
				case ERASE::CURRENT_LINE:
					printf("\033[2K");
					break;
				case ERASE::TO_TOP_OF_THE_SCREEN:
					printf("\033[J");
					break;
				case ERASE::TO_BOTTOM_OF_THE_SCREEN:
					printf("\033[1J");
					break;
				case ERASE::SCREEN:
					printf("\033[2J");
					break;
			}

			return *this;
		}
		Base& Base::operator()(PRINT print)
		{
			return *this;
		}
		Base& Base::operator()(SCROLL::DIRECTION direction, uint16_t magnitude)
		{
			return *this;
		}
	}
}
