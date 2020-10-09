#pragma once

namespace system
{
	namespace media
	{
		class Font
		{
		public:
			Font(const char &fontCode);
			~Font();

			static const unsigned fontCount = 256;
			static const unsigned fontHeight = 16;
			static const unsigned fontWidth = 8; // unsigned char = fontWidth = 8bits

			using FontTable = const unsigned char[fontCount][fontHeight];
			using FontRows = const unsigned char *;

			FontRows getFontRows() const;

		private:
			static const FontTable fontTable;
			char fontCode;
		}; // class Font

	} // namespace media

} // namespace system
