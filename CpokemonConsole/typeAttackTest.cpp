/*std::cout << "Hello World!\n";

//TypeChart chart;

std::string input = "";
while (true) {
    std::cout << "\nEnter the attacking type (0-17), or x to exit\n";
    std::cin >> input;
    if (input == "x" || input == "X") {
        break;
    }
    int attackType = std::stoi(input);
    if (attackType > 17) {
        continue;
    }
    std::cout << "\nEnter the 1st defending type (0-17)\n";
    std::cin >> input;
    int defType1 = std::stoi(input);
    if (defType1 > 17) {
        defType1 = 0;
    }
    std::cout << "\nEnter type 2 (0-17), or any other number to skip\n";
    std::cin >> input;
    int defType2 = std::stoi(input);
    if (defType2 > 17) {
        defType2 = 18;
    }
    float effectiveness = chart.GetEffectiveness((Typings)attackType, (Typings)defType1, (Typings)defType2);

    //some temp data
    int attackerATK = 99;
    int defenderDEF = 30;
    int attackPOW = 150;
    int attackerLVL = 100;

    float randomness = 1.0f; //(rand() % 15 + 85) / 100.0f;
    float critical = 1.0f;
    int critChance = rand() % 26;
    if (critChance == 0) {
        critical = 1.5f;
    }

    //plug it into the pokemon damage formula
    //source: https://bulbapedia.bulbagarden.net/wiki/Damage
    //(this will be moved to the library in a future version)
    int damage = ((((2 * attackerLVL) / 5.0f + 2) * attackPOW * (attackerATK / defenderDEF)) / 50.0f + 2)
        * critical * randomness * effectiveness;

    std::cout << "attack type: " << TypeToString((Typings)attackType) << std::endl;
    std::cout << "defender types: " << TypeToString((Typings)defType1) << "/" << TypeToString((Typings)defType2) << std::endl;
    std::cout << "the damage dealt would roughly be: " << damage << std::endl;
*/