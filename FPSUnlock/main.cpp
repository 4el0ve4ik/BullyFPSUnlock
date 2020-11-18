#include <Windows.h>

BOOL __stdcall DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	if (fdwReason == 1) {
		DWORD oldProt = 0;
		void* adr = reinterpret_cast<void*>(0x4061BF);
		VirtualProtect(adr, 6, PAGE_EXECUTE_READWRITE, &oldProt);
		*reinterpret_cast<BYTE*>(0x4061BF) = 0x2B;
		*reinterpret_cast<BYTE*>(0x4061C2) = 0xEB;
		VirtualProtect(adr, 6, oldProt, NULL);
	}
	return TRUE;
}