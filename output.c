#include<stdint.h>
#define ch_bool unsigned char
#define ch_int8 int8_t
#define ch_uint8 uint8_t
#define ch_int16 int16_t
#define ch_uint16 uint16_t
#define ch_int32 int32_t
#define ch_uint32 uint32_t
#define ch_int64 int64_t
#define ch_uint64 uint64_t
#define ch_real32 float
#define ch_real64 double
#define ch_string char*
#define ch_true_t1
#define ch_false_t0


typedef struct data {
ch_int64 a;
ch_uint32 b;
ch_bool c;
} data;

ch_uint64 data__func1 (data *this, ch_int64 a, ch_int64 b) {
ch_int64 c = (*this).a;
ch_int64 d = c;
return (ch_uint64)(a + b + c * d) + (ch_uint64)((*this).b);
}
ch_int64 data__func2 (data *this) {
return (ch_int64)((*this).a + (*this).b);
}
ch_uint32 globalFunc (data a, data b) {
return a.b + b.b;
}
ch_uint64 globalFunc2 (data a, ch_int64 b, ch_int64 c) {
return data__func1(&(a),b, c);
}
