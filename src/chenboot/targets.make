LIBS_CHENBOOT_OBJS = \
	src/chenboot/chenboot.o

OUTPUT_LIBS += $(OUTPUT_LIBDIR)libchenboot.a
OUTPUT_LIBS_OBJS += $(LIBS_CHENBOOT_OBJS)

LIBS_CHENBOOT_INCS =

src/chenboot/%.o: src/chenboot/%.S
	$(TARGET_AS) -o $@ $< $(TARGET_ASFLAGS)

$(OUTPUT_LIBDIR)libchenboot.a: $(LIBS_CHENBOOT_OBJS) $(LIBS_CHENBOOT_INCS)
	$(TARGET_AR) crs $@ $(LIBS_CHENBOOT_OBJS)

