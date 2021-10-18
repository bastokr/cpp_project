

#include <iostream> 
#include <string>

using namespace  std; 

int main()
{
	 int counter = 0, markers = 12;
	 enum Marker { DOT, HAT, AT, COMMA };
	 while (counter < markers) {
		   std::cout.width(counter + 2);
		   switch (counter % 4) {
		       case Marker::DOT:
				   cout << '.';
		            break;
		        case Marker::COMMA:
					cout << '^';
		            break;
		        case Marker::HAT:
					cout << '@';
		            break;
		        case Marker::AT:
					cout << ',';
		            break;
		
		}
		  std::cout << "\n";
		  counter++;
		
	}
	  


}