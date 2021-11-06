#include <stdio.h>

typedef enum {left = 0, mid = 1, right = 2} t_which_tower;
typedef unsigned int uint;

static uint g_heights[3];

static void print_move(t_which_tower from, t_which_tower to)
{
	char line_template[6] = "     ";
	uint total_height = 0;
	for (uint i = 0; i < 3; ++i) //silly way to do it...
		total_height += g_heights[i];
	// ^^ do we want the max instead? (i feel like this is better)

	for (uint i = total_height; i > 0; --i)
	{
		for (uint j = 0; j < 3; ++j)
			line_template[2*j] = (i <= g_heights[j])? 'M' : ' ';
		if (i == g_heights[from] + 1)
			line_template[2*from] = 'O';
		if (i == g_heights[to])
			line_template[2*to] = 'X';
		printf("%s\n", line_template);
	}
	printf("_ _ _\n"
	       "*****\n");
}	

static void hanoi_helper(uint height, t_which_tower from, t_which_tower to);
//^^ needed for recursion
static void hanoi_helper(uint height, t_which_tower from, t_which_tower to)
{
	if (height == 0)
		return ;
	t_which_tower other_tow = (t_which_tower) 3 - from - to; 
	//^^ 3 bc  left + mid + right = 3 not bc 3 towers
	hanoi_helper(height - 1, from, other_tow);
	--g_heights[from];
	++g_heights[to];
	print_move(from, to);
	hanoi_helper(height - 1, other_tow, to);
}

void print_hanoi(uint n) 
{
	printf("legend : plate O was moved to X\n");
	g_heights[left] = n;
	g_heights[mid] = 0;
	g_heights[right] = 0;
	hanoi_helper(n, left, right);
}

#ifdef MAIN
#include <stdlib.h>

int main (int ac, char **av)
{
	if (ac != 2)
		return (-1);
	uint n = atoi(av[1]);
	print_hanoi(n);
	return 0;
}
#endif
