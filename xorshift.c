#include <stdint.h>

typedef struct {
    int32_t a;
} XorShift32_state;

int32_t xorshift32(XorShift32_state *state, int32_t max)
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	int32_t x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return state->a = (x % max);
}
