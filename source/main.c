#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <wafel/dynamic.h>
#include <wafel/ios_dynamic.h>
#include <wafel/utils.h>
#include <wafel/patch.h>
#include <wafel/ios/svc.h>
#include <wafel/ios/memory.h>

// This fn runs before everything else in kernel mode.
// It should be used to do extremely early patches
// (ie to BSP and kernel, which launches before MCP)
// It jumps to the real IOS kernel entry on exit.
__attribute__((target("arm")))
void kern_main()
{
    // Make sure relocs worked fine and mappings are good
    debug_printf("we in here isfshax patch kern %p\n", kern_main);

    debug_printf("init_linking symbol at: %08x\n", wafel_find_symbol("init_linking"));

    // Patch IOS-FS thing
    ASM_PATCH_K(0x1072272C, "mvn r5, #0x8000");

    // Block boot1 updating
    ASM_T_PATCH_K(0x05100688,
                  "movs r0, #0\n"
                  "bx lr\n"
                  );

    // patch out the format with an undefined instruction (crash)
    U32_PATCH_K(0x107e8178,0xFFFFFFFF);

    debug_printf("isfshax patch applied\n");
}

// This fn runs before MCP's main thread, and can be used
// to perform late patches and spawn threads under MCP.
// It must return.
void mcp_main()
{


}
