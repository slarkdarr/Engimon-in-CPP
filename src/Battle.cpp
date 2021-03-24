#include "Battle.hpp"
#include <iostream>
using namespace std;



Player* Battle::battle(Player* myplayer, ListEnemy& listmusuh){
    // cout << "BATTLE!" << endl;
    Engimon* engimonMusuh = myplayer->getClosestEnemy();
    // cout << "Berhasil menemukan musuh!" << endl;
    // Jika ada musuh (tidak null ptr)
    if (engimonMusuh)
    {
        ulanglagi:
        auto myengimon = myplayer->getEngimon();

        int playerLvl = myplayer->getLevel();
        int enemyLvl = engimonMusuh->getLevel();

        float playerMaxElAdv = Engimon::maxElAdv(myengimon,engimonMusuh);
        float enemyMaxElAdv = Engimon::maxElAdv(engimonMusuh,myengimon);
        
        float powerPlayer = (playerLvl * playerMaxElAdv) + myengimon->sumSkillPower();
        float powerEnemy = (enemyLvl * enemyMaxElAdv) + engimonMusuh->sumSkillPower();

        if (powerPlayer < powerEnemy)
        {
            std::cout << "Kalah power, Engimon Anda Mati" << std::endl;
            delete myplayer->getEngimon();

            myplayer->setActiveEngimon(nullptr);


            // Jika tidak ada engimon tersisa
            if (myplayer->inventory->isEngimonBagEmpty())
            {
                std::cout << "Tidak Ada Engimon Tersisa" << std::endl;
                delete myplayer;
                return nullptr;
            }
            else
            {   
                myplayer->inventory->printAllEngimonInfo();
                Bag<Engimon>* temp = myplayer->inventory->listEngimon();
                int n1 = Player::validasiInput("Pilih Engimon: ", 0 , temp->neff, -1);
                Engimon* temp2 = new Engimon(*temp->listItem[n1-1]);
                myplayer->inventory->removeEngimon(n1);
                myplayer->setActiveEngimon(temp2);
                delete temp;
                goto ulanglagi;
            }
        }
        // Jika Menang Power
        else
        {
            std::cout << "Engimon Di Kalahkan\n";
            
            if (!myplayer->inventory->isFull())
            {
                std::cout << "Engimon Menjadi Milik Anda" << std::endl;
                std::cout << "Beri Nama Engimon Baru anda : ";
                string nama;
                std::cin >>  nama;
                engimonMusuh->setName(nama);
                myplayer->inventory->addEngimon(*engimonMusuh);
                std::cout << std::endl;
            }
            else 
            {
                std::cout << "Inventory Penuh!" << std::endl;
                delete engimonMusuh;
            }
            // RESPAWN MUSUH
            for (int i = 0; i < listmusuh.jmlhMusuh; i++)
            {
                if (listmusuh.listEnemy[i]->getEngimon() == engimonMusuh)
                {
                    listmusuh.listEnemy[i]->setEngimon(nullptr);
                    delete listmusuh.listEnemy[i];
                    listmusuh.listEnemy[i] = new Enemy(*listmusuh.map, 
                    rand() % 5, abs(rand() % (myplayer->getLevel() + 5) + (myplayer->getLevel() - 5)));
                    break;
                }
            }
            // Jika Engimon Suicide saat Penambahan xp
            if (!myplayer->getEngimon()->addExp(100))
            {
                myplayer->setActiveEngimon(nullptr);
            }
        }
    }
    return myplayer;
}