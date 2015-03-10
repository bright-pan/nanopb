# Include the nanopb provided Makefile rules
include ../../extra/nanopb.mk

# Compiler flags to enable all warnings & debug info
CFLAGS = -Wall -Werror -g -O0
CFLAGS += -I$(NANOPB_DIR)

# C source code files that are required
CSRC += alltypes.pb.c sdp.pb.c                # The compiled protocol definition
CSRC += $(NANOPB_DIR)/pb_encode.c  # The nanopb encoder
CSRC += $(NANOPB_DIR)/pb_decode.c  # The nanopb decoder
CSRC += $(NANOPB_DIR)/pb_common.c  # The nanopb common parts

# Build rule for the main program
all: $(CSRC)
	$(CC) $(CFLAGS) -odecode_alltypes decode_alltypes.c $(CSRC)
	$(CC) $(CFLAGS) -oencode_alltypes encode_alltypes.c $(CSRC)

# Build rule for the protocol
sdp.pb.c: sdp.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. $^
alltypes.pb.c: alltypes.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. $^
clean:
	rm -rf decode_alltypes encode_alltypes *.pb.* *.o

