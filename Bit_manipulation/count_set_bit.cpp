#include "bit.h"
#include <cstdio>

/**
 * Count the number of Set Bits
 */
int count_set_bits(unsigned int num) {
	// Method 1
	unsigned int i = 1, count = 0;
	unsigned int cached_num = num;

	while(num){
		if (i&num){
			count++;
		}
		num = num>>1;
	}

	printf("\nNumber of Set Bits in %d are %d\n", cached_num, count);


	// Method 2
	/* When we subtract 1 from a number then if
	 * - LSB of the num is 1 then its toggled and then done you have num-1
	 * - LSB of the num is 0 then all the bits are toggled till the 1st SET_BIT(1)
	 * 		of the number and done you have a num-1.
	 *
	 * 	So when you do (num & (num-1)) if clears the Right Most set Bit.
	 */
	count = 0;
	num = cached_num;
	while (num != 0){
		printf("\nNum = %d", num);
		num = (num & (num-1));
		count++;
	}
	printf("\nNumber of Set Bits in %d are %d\n", cached_num, count);

	return count;
}
