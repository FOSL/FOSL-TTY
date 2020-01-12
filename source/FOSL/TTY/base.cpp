#include "FOSL/TTY/base.hpp"

namespace FOSL
{
	namespace TTY
	{
		// TODO: IMPLEMENT BASED ON: http://www.termsys.demon.co.uk/vtansi.htm#print

		base::base(FILE *initial_stream)
			: stream(initial_stream)
		{
		}

		uint8_t base::get_device_code(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
			return 0;
		}
		DEVICE_STATUS base::get_device_status(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
			return DEVICE_STATUS::OK;
		}
		cursor_position base::get_cursor_position(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
			return cursor_position { 0, 0 };
		}

		void base::set_line_wrap(bool enable)
		{
			switch (enable)
			{
				case true:  printf("\0337h");
				case false: printf("\0337l");
			}
		}
		void base::set_cursor_position(cursor_position cursor_position)
		{
			printf("\033[%u;%uf", cursor_position.y, cursor_position.x);
		}
		void base::set_cursor_position(uint16_t x, uint16_t y)
		{
			printf("\033[%u;%uf", y, x);
		}

		void base::reset_device(void)
		{
			printf("\033c");
		}
		void base::print_screen(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void base::print_line(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void base::shift_cursor_position(CURSOR::DIRECTION direction, uint16_t magnitude)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void base::save_cursor_position(void)
		{
			printf("\033[s");
		}
		void base::save_cursor_and_attrs(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void base::restore_cursor_position(void)
		{
			printf("\033[u");
		}
		void base::restore_cursor_and_attrs(void)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
		}
		void base::define_key(char const*key, char const*definition)
		{
			assert(!"THIS METHOD IS YET TO BE IMPLEMENTED!");
		}

		base &base::operator()(TAB tab)
		{
			return *this;
		}
		base &base::operator()(ERASE erase)
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
		base &base::operator()(PRINT print)
		{
			return *this;
		}
		base &base::operator()(SCROLL::DIRECTION direction, uint16_t magnitude)
		{
			return *this;
		}
	}
}
