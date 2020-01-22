/**
* Copyright © 2019 Denis Z. (code4un@yandex.ru) All rights reserved.
* Authors: Denis Z. (code4un@yandex.ru)
* All rights reserved.
* License: see LICENSE.txt
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
* IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// HEADER
#include "main.hpp"

// WINDOWS
#if defined( WIN32 ) || defined( WIN64 ) || defined( WINDOWS )

// Include Windows API
#include <Windows.h>

// Include stringbuf
#include <sstream>

#endif
// WINDOWS

// ===========================================================
// MAIN
// ===========================================================

// WINDOWS
#if defined( WIN32 ) || defined( WIN64 ) || defined( WINDOWS )

namespace c0de4un
{

	// -----------------------------------------------------------

	/**
	 * @see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
	**/
	class MBuf final : public std::stringbuf
	{

	public:

		// -----------------------------------------------------------

		int sync()
		{
			std::fputs(str().c_str(), stdout);
			str("");
			return 0;
		}

		// -----------------------------------------------------------

	}; /// c0de4un::MBuf

	// -----------------------------------------------------------

} /// c0de4un

#endif
// WINDOWS

void loadLib()
{
	// WINDOWS
#if defined( WIN32 ) || defined( WIN64 ) || defined( WINDOWS )
		std::cout << "Library loaded." << std::endl;
		const int sumResult = Sum(2, 2);
		std::cout << "result = " << std::to_string(sumResult) << std::endl;
#endif
	// WINDOWS
}

int main()
{
	// WINDOWS
#if defined( WIN32 ) || defined( WIN64 ) || defined( WINDOWS )
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IONBF, 0); // @see http://www.cplusplus.com/reference/cstdio/setvbuf/
	c0de4un::MBuf consoleBuf;
	std::cout.rdbuf(&consoleBuf);
#endif
	// WINDOWS

	// Print
	std::cout << u8"Привет мир !" << std::endl;

	// Use SHARED Library.
	loadLib();

	// Wait input.
	std::cin.get();

	// OK
	return 0;
}

// -----------------------------------------------------------