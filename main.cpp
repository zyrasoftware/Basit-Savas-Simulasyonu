#include <iostream>
#include <ctime>
#include <cstdlib>

class Player {
public:
    Player(const std::string& name) : name(name), health(100) {}

    void attack(Player& target) {
        int damage = rand() % 20 + 1; 
       
        std::cout << name << " " << "hedefine saldırıyor ve " << target.getName() << " adlı oyuncuya " << damage << " hasar veriyor." << std::endl;
        target.takeDamage(damage);
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
      
        std::cout << name <<  damage << " hasar alıyor. Kalan can: " << health << std::endl;
        if (health == 0) {
            std::cout << name << " Mağlup Oldu!" << std::endl;
        }
    }

    const std::string& getName() const {
        return name;
    }

    bool isAlive() const {
        return health > 0;
    }

private:
    std::string name;
    int health;
};

int main() {
    setlocale(LC_ALL, "Turkish");
    // Rastgele sayı üretimi için seed ayarla
    std::srand(std::time(0));

    // Oyuncu nesnelerini oluştur
    Player player1("Player 1");
    Player player2("Player 2");

    // Savaş başlasın
    while (player1.isAlive() && player2.isAlive()) {
        player1.attack(player2);
        if (!player2.isAlive()) {
            break; // Eğer ikinci oyuncu öldüyse döngüyü sonlandır
        }

        player2.attack(player1);
        if (!player1.isAlive()) {
            break; // Eğer birinci oyuncu öldüyse döngüyü sonlandır
        }
    }

    return 0;
}
