#ifndef _PB_DECODE_H_
#define _PB_DECODE_H_

#include <stdbool.h>
#include "pb.h"

// Decode from stream to destination struct.
// The actual struct pointed to by dest must match the description in fields.
bool pb_decode(pb_istream_t *stream, const pb_field_t fields[], void *dest_struct);

/* --- Helper functions ---
 * You may want to use these from your caller or callbacks.
 */

pb_istream_t pb_istream_from_buffer(uint8_t *buf, size_t bufsize);

bool pb_decode_varint32(pb_istream_t *stream, uint32_t *dest);
bool pb_decode_varint64(pb_istream_t *stream, uint64_t *dest);

bool pb_skip_varint(pb_istream_t *stream);
bool pb_skip_string(pb_istream_t *stream);

/* --- Field decoders ---
 * Each decoder takes stream and field description, and a pointer to the field
 * in the destination struct (dest = struct_addr + field->data_offset).
 * For arrays, these functions are called repeatedly.
 */

bool pb_dec_uint32(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_sint32(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_fixed32(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_uint64(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_sint64(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_fixed64(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_bool(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_enum(pb_istream_t *stream, const pb_field_t *field, void *dest);

bool pb_dec_float(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_double(pb_istream_t *stream, const pb_field_t *field, void *dest);

bool pb_dec_bytes(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_string(pb_istream_t *stream, const pb_field_t *field, void *dest);
bool pb_dec_submessage(pb_istream_t *stream, const pb_field_t *field, void *dest);

typedef bool (*pb_decoder_t)(pb_istream_t *stream, const pb_field_t *field, void *dest);

/* --- Function pointers to field decoders ---
 * Order in the array must match pb_action_t LTYPE numbering.
 */
const pb_decoder_t PB_DECODERS[16];

#endif
