long loop(long x, long n)
{
	int result = 0;
	int mask;
	for (mask = 1; mask != 0; mask = mask << (~(~0 << 8) & n))
	{
		result ^= (x & mask);
	}
	return result;
}