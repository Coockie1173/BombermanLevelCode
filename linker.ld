SECTIONS {
    . = 0x80043000;

    .text :
    {
        *(.text.start)
        *(.text)
    }

    .data :
    {
        *(.data)
        *(.data.rel.local*)
        *(.MIPS.abiflags)
        *(.reginfo)     
    }
}
