#include <stdio.h>

struct person {
	int age;
	float favorite_number;
};

void print_person(struct person p) {
	p.age = 20;
	printf("The person is %d years old, and their favorite number is %.3f\n",
		p.age,
		p.favorite_number
	);
}

struct person create_default_person() {
	struct person p;
	p.age = 0;
	p.favorite_number = 0.0;
	return p;
}

int main() {
	struct person joe;
	joe.age = 28;
	joe.favorite_number = 3.14;

	print_person(joe);

	struct person lame_default_person = create_default_person();
}
