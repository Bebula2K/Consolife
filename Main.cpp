//build with "g++ -o Game Main.cpp"

/*TODO:

[-] Add better UI

[+] Leveling system

[-] Combat probably

[-] More ways to gain stats

[+] Cls command

[-] Save game

*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
using namespace std;

// ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


class Player {
public:
    int Intelligence = 0;
    int Strength = 0;
    float Hunger = 100;
    int Fatigue = 0;
    float Money = 0;
    int Food = 10;
    int Rocks = 0;
    int Coal = 0;
    int IronOre = 0;
    int CopperOre = 0;
    int MiningLevel = 0;
    float MiningXp = 0;
    float MiningXpNeeded = 100;

    void Eat() {
        if (Food >= 1) {
            Food -= 1;
            Hunger += 1;
            cout << "You ate some food." << endl;
        } else {
            cout << "You don't have enough food to eat." << endl;
        }
    }

    void Info(){
    	std::cout << "Intelligence " << "  |   " << YELLOW << Intelligence << "/99" << RESET << endl;
    	std::cout << "Strength " << "      |   " << YELLOW << Strength << "/99" << RESET << endl;
        std::cout << "Mining level " << "  |   " << YELLOW << MiningLevel << "/99" << RESET << endl;
        std::cout << "Mining XP " << "     |   " << YELLOW << MiningXp << "/" << MiningXpNeeded << RESET << endl;
        std::cout << "Money " << "         |   " << YELLOW << Money << RESET << endl;
    	std::cout << "Fatigue " << "       |   " << YELLOW << Fatigue << RESET << endl;
        std::cout << "Hunger " << "        |   " << YELLOW << Hunger << RESET << endl;

    }

    void Inventory(){
    	std::cout << "Food " << "          |   " << YELLOW << Food << RESET << endl;
    	std::cout << "Rocks " << "         |   " << YELLOW << Rocks << RESET << endl;
    	std::cout << "Coal " << "          |   " << YELLOW << Coal << RESET << endl;
    	std::cout << "Copper Ore " << "    |   " << YELLOW << CopperOre << RESET << endl;
    	std::cout << "Iron Ore " << "      |   " << YELLOW << IronOre << RESET << endl;
    }

    void PlayerSleep(){
    	if(Fatigue <= 1){
    		cout << "Sleeping..." << endl;
    		sleep(1);
    		Fatigue -= 1;
    	}
    	if (Fatigue = 0){
    		cout << "" << endl;
    	}
    }
void Mine() {
    cout << "Mining in progress";
    cout.flush();
    for (int i = 0; i < 10; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << endl;
    

    srand(static_cast<unsigned int>(time(nullptr)));

    int rocksMined = rand() % 10 + 1;
    int coalMined = 0;
    int copperOreMined = 0;
    int ironOreMined = 0;

    if (MiningLevel >= 3)
        coalMined = rand() % 5 + 1;
    if (MiningLevel >= 5)
        copperOreMined = rand() % 3 + 1;
    if (MiningLevel >= 10)
        ironOreMined = rand() % 2 + 1;

    Rocks += rocksMined;
    MiningXp += rocksMined;

    if (MiningLevel >= 3) {
        Coal += coalMined;
        MiningXp += coalMined;
    }
    if (MiningLevel >= 5) {
        CopperOre += copperOreMined;
        MiningXp += copperOreMined;
    }
    if (MiningLevel >= 10) {
        IronOre += ironOreMined;
        MiningXp += ironOreMined;
    }
    Fatigue += 1;
    Hunger -= 1;

    cout << "Mining Results:" << endl;
    cout << "Rocks mined: " << YELLOW << rocksMined << RESET << endl;
    if (MiningLevel >= 3)
        cout << "Coal mined: " << YELLOW << coalMined << RESET << endl;
    if (MiningLevel >= 5)
        cout << "Copper ore mined: " << YELLOW << copperOreMined << RESET << endl;
    if (MiningLevel >= 10)
        cout << "Iron ore mined: " << YELLOW << ironOreMined << RESET << endl;
    cout << "Fatigue increased by" << YELLOW << " 1 " << RESET << "and hunger dropped by" << YELLOW << " 1" << RESET << endl;
    cout << "You gained " << GREEN << rocksMined + coalMined + copperOreMined + ironOreMined << RESET << " XP from the mining trip." << endl;

    if (MiningXp >= MiningXpNeeded) {
        MiningLevelUp();
    }
}


void Sell() {
    cout << "Your inventory: " << endl;
    cout << "[" << GREEN << "1" << RESET << "] Food: " << YELLOW << Food << RESET << endl;
    cout << "[" << GREEN << "2" << RESET << "] Rocks: " << YELLOW << Rocks << RESET << endl;
    cout << "[" << GREEN << "3" << RESET << "] Coal: " << YELLOW << Coal << RESET << endl;
    cout << "[" << GREEN << "4" << RESET << "] Copper Ore: " << YELLOW << CopperOre << RESET << endl;
    cout << "[" << GREEN << "5" << RESET << "] Iron Ore: " << YELLOW << IronOre << RESET << endl;

    cout << "What would you like to sell? Enter the corresponding number (1-5): ";
    int choice;
    cin >> choice;

    int quantity;
    switch (choice) {
        case 1:
            cout << "Enter the quantity of food you want to sell: ";
            cin >> quantity;
            if (quantity > 0 && quantity <= Food) {
                Money += quantity * 3;
                Food -= quantity;
                cout << "You sold " << YELLOW << quantity << RESET << " food for " << GREEN << quantity * 3 << RESET << " money." << endl;
            } else {
                cout << "Invalid quantity. Please try again." << endl;
            }
            break;
        case 2:
            cout << "Enter the quantity of rocks you want to sell: ";
            cin >> quantity;
            if (quantity > 0 && quantity <= Rocks) {
                Money += quantity;
                Rocks -= quantity;
                cout << "You sold " << YELLOW << quantity << RESET << " rocks for " << GREEN << quantity << RESET << " money." << endl;
            } else {
                cout << "Invalid quantity. Please try again." << endl;
            }
            break;
        case 3:
            cout << "Enter the quantity of coal you want to sell: ";
            cin >> quantity;
            if (quantity > 0 && quantity <= Coal) {
                Money += quantity * 5;
                Coal -= quantity;
                cout << "You sold " << YELLOW << quantity << RESET << " coal for " << GREEN << quantity * 5 << RESET << " money." << endl;
            } else {
                cout << "Invalid quantity. Please try again." << endl;
            }
            break;
        case 4:
            cout << "Enter the quantity of copper ore you want to sell: ";
            cin >> quantity;
            if (quantity > 0 && quantity <= CopperOre) {
                Money += quantity * 10;
                CopperOre -= quantity;
                cout << "You sold " << YELLOW << quantity << RESET << " copper ore for " << GREEN << quantity * 10 << RESET << " money." << endl;
            } else {
                cout << "Invalid quantity. Please try again." << endl;
            }
            break;
        case 5:
            cout << "Enter the quantity of iron ore you want to sell: ";
            cin >> quantity;
            if (quantity > 0 && quantity <= IronOre) {
                Money += quantity * 15;
                IronOre -= quantity;
                cout << "You sold " << YELLOW << quantity << RESET << " iron ore for " << GREEN << quantity * 15 << RESET << " money." << endl;
            } else {
                cout << "Invalid quantity. Please try again." << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

void Shop(){
    cout << "Welcome to the shop! Enter" << endl;
    cout << "[" << GREEN << "1" << RESET << "] Buy Food" << endl;
    cout << "[" << GREEN << "2" << RESET << "] Quit" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter the quantity of food you want to buy: ";
            int quantity;
            cin >> quantity;
            if (quantity > 0) {
                int totalPrice = quantity * 50;
                if (Money >= totalPrice) {
                    Money -= totalPrice;
                    Food += quantity;
                    cout << "You bought " << YELLOW << quantity << RESET << " food for " << GREEN << totalPrice << RESET << " money." << endl;
                } else {
                    cout << "You don't have enough money to buy that many food." << endl;
                }
            } else {
                cout << "Invalid quantity. Please try again." << endl;
            }
            break;
        case 2:
            cout << "Exiting shop." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

void Cls(){
    system("cls");
}

void MiningLevelUp() {
        MiningLevel += 1;
        MiningXp -= MiningXpNeeded;
        MiningXpNeeded *= 1.2;
        cout << GREEN << "Congratulations!" << RESET << " You leveled up Mining to Level " << YELLOW << MiningLevel << RESET << "!" << endl;
        cout << "XP needed for next level: " << MiningXpNeeded << endl;
    }

};

void processCommand(const string& command, Player& player) {
    // Process different commands
    if (command == "Help") {
        cout << "Basic commands:" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Eat" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Mine" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Sleep" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Sell" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Info" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Inventory" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Shop" << endl;
        cout << "[" << GREEN << "*" << RESET << "] Cls" << endl;
        // Add code to handle the 'help' command
    } else if (command == "Quit") {
        cout << "Quit command executed. Exiting program." << endl;
        exit(0);
    } else if (command == "Eat") {
        player.Eat();
    }else if (command == "Info"){
    	player.Info();
    }else if (command == "Inventory"){
    	player.Inventory();
    } else if (command == "Sleep"){
    	player.PlayerSleep();
    }
    else if (command == "Mine"){
    	player.Mine();
    } else if (command == "Sell"){
        player.Sell();
    } else if (command == "Shop"){
        player.Shop();
    } else if (command == "Cls"){
        player.Cls();
    } else {
        cout << "Unknown command: " << command << endl;
    }

}

int main(int argc, char const* argv[]) {
    Player player;


    string command;
    while (true) {
        cout << "> ";
        getline(cin, command);

        if (!command.empty()) {
            processCommand(command, player);
        }
    }

    return 0;
}
