/**
* Copyright � 2019 Denis Z. (code4un@yandex.ru) All rights reserved.
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

#ifndef C0DE4UN_MYLIB_H
#define C0DE4UN_MYLIB_H

// -----------------------------------------------------------

// ===========================================================
// INCLUDES
// ===========================================================

// ===========================================================
// CONFIGS
// ===========================================================

#ifdef MYLIB_IMPORT
#define MYLIB_DECLSPEC __declspec(dllimport)
#elif defined( MYLIB_STATIC )
#define MYLIB_DECLSPEC __declspec(dllexport)
#else defined( MYLIB_EXPORT )
#define MYLIB_DECLSPEC
#endif

// ===========================================================
// EXTERN C
// ===========================================================

extern "C"
{

	// -----------------------------------------------------------

	int Sum(const int pLhs, const int pRhs);

	// -----------------------------------------------------------

} /// extern C

// -----------------------------------------------------------

#endif // !C0DE4UN_MYLIB_H