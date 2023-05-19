#include<iostream>
#include<cassert>
#include<list>
#include<memory>

using namespace std;

class Player
    :public enable_shared_from_this<Player>
{
public:
  std::weak_ptr<Player> companion;
  ~Player() { std::cout << "~Player\n"; }
};

int main()
{
    std::shared_ptr<Player> jasmine = std::make_shared<Player>(A);
    std::shared_ptr<Player> albert = std::make_shared<Player>(B);

    jasmine->companion = albert; // (1)
    albert->companion = jasmine; // (2)
}//ЖОПА, я не знаю как это делать, вообще не вдупляю как работает shared_ptr