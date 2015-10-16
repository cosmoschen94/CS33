int switch_prob(int x, int n)
{
	int result = x;

	switch(n) {

		case 50:
		case 52:
			x = x << 2;
			break;

		case 53:
			x = x >> 2;
			break;

		case 54:
			x *= 3;

		case 55:
			x *= x;

		default:
			x += 10;
	}
}