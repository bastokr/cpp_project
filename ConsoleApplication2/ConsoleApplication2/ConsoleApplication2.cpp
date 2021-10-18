

#include <iostream> 
#include <string>
#define  CATEGORIES 5

using namespace  std;
// function 1: reads five category names into the cat array
void get_category(std::string cat[CATEGORIES]);

// function 2: gets five values for each category
void get_values(double values[CATEGORIES], std::string cat[CATEGORIES]);

// function 3: computes the total value and stores in total
void compute_total(double& total, double vals[CATEGORIES]);

// function 4: computes the longest category name and stores in longest
void get_longest_category_name(int& longest, std::string cat[CATEGORIES]);

// function 5: prints to std : cout the five category bar chart
void bar_chart(std::string cat[CATEGORIES], double values[CATEGORIES], int lcl, double total);

int main() {
	std::string categories[CATEGORIES];
	double values[CATEGORIES]; double total{ 0.0 }; int lcl{ 0 };

	while (true) {
		get_category(categories);
		get_values(values, categories);
		compute_total(total, values);
		get_longest_category_name(lcl, categories);

		std::cout << "\n Categories as a Percentage of the Total ( category_amount /" << total << ")\n";
		std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		bar_chart(categories, values, lcl, total);
		std::cout << "\n Enter y to create another bar chart , 24 or any other key to exit : ";
		std::string response; std::cin >> response; std::cout << "\n";
		if (response != "y")
			break;
		lcl = 0; total = 0.0;

		 
		 
	}// while

}// main
//
// Implementations go below
//

void get_category(std::string cat[CATEGORIES]){
	std::cout << " Enter in the category names for your five -bar bar chart :\n";
	int count = 0;
	while (count < CATEGORIES) {
		std::cin >> cat[count];

		++count;
	}
}

// function 2: gets five values for each category
void get_values(double values[CATEGORIES], std::string cat[CATEGORIES]) {
	int count = 0;
	while (count < CATEGORIES) {
 
		std::cout << "How many in the " + cat[count] + " category ? ";
		std::cin >> values[count];
		++count;
	}
	 
}

// function 3: computes the total value and stores in total
void compute_total(double& total, double vals[CATEGORIES]) {

  	for (int i = 0; i < CATEGORIES;i++) {
		total = total + vals[i];
 	}
 	//std::cout << "total value= " << total  << endl;

}

// function 4: computes the longest category name and stores in longest
void get_longest_category_name(int& longest, std::string cat[CATEGORIES]) {
	 
	longest = 0;
   	for (int i = 0; i < CATEGORIES; i++) {
		if (cat[i].length() > longest) longest = cat[i].length();
	}

	//std::cout << "total value= " << longest << endl;

}

// function 5: prints to std : cout the five category bar chart
void bar_chart(std::string cat[CATEGORIES], double values[CATEGORIES], int lcl, double total) {
 
	std::cout << fixed;
	std::cout.precision(2);
  
	lcl = lcl + 3;
	std::cout << endl;
  
	for (int i = 0; i < CATEGORIES; i++) {
		cout.fill(' ');
		cout << cat[i];
		cout.width(lcl - cat[i].length());
		cout << '*';
		cout.width(lcl + round((values[i] / total) * 100));
		cout.fill('*');
		cout << right << ((values[i] / total) * 100) << endl;
  	}
  
}
 