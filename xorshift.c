#include <stdint.h>

#define MOD 100

typedef struct {
    uint32_t a;
} XorShift32_state;

int32_t xorshift32(XorShift32_state *state)
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	uint32_t x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return state->a = (x % MOD);
}
    
