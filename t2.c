#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>

int mul_inv(uint64_t a, uint64_t b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(uint64_t x, uint64_t y, uint64_t p)
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    int n, e, c;
    FILE *fptr;

    if ((fptr = fopen("C:\\Users\\Eduardo\\Desktop\\arquivos\\03.in","r")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    fscanf(fptr,"%d" "%d" "%d", &n, &e, &c);

    printf("Value of n=%d \nValue of e=%d \nValue of c=%d", n, e, c);
    fclose(fptr);

    int p = floor(sqrt(n));
    if (p%2==0){
        p = p + 1;
    }
    printf("\n\np=%d", p);
    while(n%p != 0){
        p = p-2;
        printf("\n\np=%d", p);
    }
    printf("\n\np=%d", p);

    int q = n / p;
    printf("\n\nq=%d", q);

    //int d = (1/pow(e, 1)) % (p-1)*(q-1);
    int d = mul_inv(e, (p-1)*(q-1));
    printf("\n\nd=%d", d);


    int mdec = power(c, d, n);
    printf("\n\nmdec=%d", mdec);

    return 0;
}
