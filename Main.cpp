//build with "g++ -o Game Main.cpp"

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player {
public:
    int Intelligence = 0;
    int Strength = 0;
    int Speed = 0;
    float Hunger = 100;
    int Fatigue = 0;
    float Money = 0;
    int Food = 10;
    int Rocks = 0;
    int Coal = 0;
    int IronOre = 0;
    int CopperOre = 0;

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
    	std::cout << "Intelligence: " << Intelligence << endl;
    	std::cout << "Strength: " << Strength << endl;
    	std::cout << "Speed: " << Speed << endl;
    	std::cout << "Money: " << Money << endl;
    	std::cout << "Fatigue: " << Fatigue << endl;
        std::cout << "Hunger: " << Hunger << endl;
    }

    void Inventory(){
    	std::cout << "Food: " << Food << endl;
    	std::cout << "Rocks: " << Rocks << endl;
    	std::cout << "Coal: " << Coal << endl;
    	std::cout << "Copper Ore: " << CopperOre << endl;
    	std::cout << "Iron Ore: " << IronOre << endl;
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
    cout << "You start to mine..." << endl;
    sleep(10);

    srand(static_cast<unsigned int>(time(nullptr)));

    int rocksMined = rand() % 10 + 1;
    int coalMined = rand() % 5 + 1;
    int copperOreMined = rand() % 3 + 1;
    int ironOreMined = rand() % 2 + 1;

    Rocks += rocksMined;
    Coal += coalMined;
    CopperOre += copperOreMined;
    IronOre += ironOreMined;
    Fatigue += 1;
    Hunger -= 1;

    cout << "Mining Results:" << endl;
    cout << "Rocks mined: " << rocksMined << endl;
    cout << "Coal mined: " << coalMined << endl;
    cout << "Copper ore mined: " << copperOreMined << endl;
    cout << "Iron ore mined: " << ironOreMined << endl;
    cout << "Fatigue increased by 1 and hunger dropped by 1." << endl;
}

void Sell() {
    cout << "Your inventory: " << endl;
    cout << "[1] Food: " << Food << endl;
    cout << "[2] Rocks: " << Rocks << endl;
    cout << "[3] Coal: " << Coal << endl;
    cout << "[4] Copper Ore: " << CopperOre << endl;
    cout << "[5] Iron Ore: " << IronOre << endl;

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
                cout << "You sold " << quantity << " food for " << quantity * 3 << " money." << endl;
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
                cout << "You sold " << quantity << " rocks for " << quantity << " money." << endl;
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
                cout << "You sold " << quantity << " coal for " << quantity * 5 << " money." << endl;
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
                cout << "You sold " << quantity << " copper ore for " << quantity * 10 << " money." << endl;
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
                cout << "You sold " << quantity << " iron ore for " << quantity * 15 << " money." << endl;
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
    cout << "[1] Buy food" << endl;
    cout << "[2] Quit" << endl;

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
                    cout << "You bought " << quantity << " food for " << totalPrice << " money." << endl;
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

};

void processCommand(const string& command, Player& player) {
    // Process different commands
    if (command == "Help") {
        cout << "Basic commands:" << endl;
        cout << "[*] Eat" << endl;
        cout << "[*] Mine" << endl;
        cout << "[*] Sleep" << endl;
        cout << "[*] Sell" << endl;
        cout << "[*] Info" << endl;
        cout << "[*] Inventory" << endl;
        cout << "[*] Shop" << endl;
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
