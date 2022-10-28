#include <Windows.h>
int main()
{
	constexpr SIZE_T dwSize = 4096;
	if (const auto lpAddress = VirtualAlloc
	( /*_In_opt_ LPVOID lpAddress       */LPVOID(0x0000010000000000)
	, /*_In_     SIZE_T dwSize          */dwSize
	, /*_In_     DWORD  flAllocationType*/MEM_RESERVE
	, /*_In_     DWORD  flProtect       */PAGE_READWRITE
	)) {
		VirtualAlloc
		( /*_In_opt_ LPVOID lpAddress       */lpAddress
		, /*_In_     SIZE_T dwSize          */dwSize
		, /*_In_     DWORD  flAllocationType*/MEM_COMMIT
		, /*_In_     DWORD  flProtect       */PAGE_READWRITE
		);
		*LPDWORD(lpAddress) = 0x12345678;
	}


}
