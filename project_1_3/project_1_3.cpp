#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========

  // Print out X
  std::cout << "x: {" << x[0];
  for (int i = 1; i < x.size(); i++){
  	std::cout << ", " << x[i];
  }
  std::cout << "}" << std::endl;

  // Print out W
  std::cout << "w: {" << w[0];
  for (int i = 1; i < w.size(); i++){
  	std::cout << ", " << w[i];
  }
  std::cout << "}" << std::endl;

  w_middle = (w.size() - 1)/2;

  for (int i = 0; i < x.size(); i++){
  	double sum = 0;
  	for (int j = 0; j < w.size(); j++){
  		int index = i - w_middle + j;
  		if (index >= 0 && index < x.size()){
  			sum += x[index]*w[j];
  		} else if (!pack_with_zeros && w_middle < 0){
  			sum += x[0] * w[j];
  		} else if (!pack_with_zeros && w_middle > x.size()){
  			sum += x[x.size()-1] * w[j];
  		}
  	}
  	y.push_back(sum);
  }

  //Print out y
  std::cout << "{" << y[0];
  for(int i = 1; i < y.size(); i++) {
    std::cout << ", " << y[i];
  }
  std::cout << "}" << std::endl;


  // =========== END ===========

  return 0;
}

