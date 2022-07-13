/*TypeChart chart;

std::string input = "";
while (true) {
    std::cout << "\nEnter type 1 (0-17), or x to exit\n";
    std::cin >> input;
    if (input == "x" || input == "X") {
        break;
    }
    int type1 = std::stoi(input);
    if (type1 > 17) {
        continue;
    }
    std::cout << "\nEnter type 2 (0-17), or any other number to skip\n";
    std::cin >> input;
    int type2 = std::stoi(input);
    if (type2 > 17) {
        type2 = 18;
    }
    std::cout << chart.GetDefenses((Typings)type1, (Typings)type2) << std::endl;
    std::cout << chart.GetOffenses((Typings)type1, (Typings)type2) << std::endl;
}*/