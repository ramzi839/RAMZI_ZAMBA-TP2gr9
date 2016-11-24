#include <iostream>
#include <random>
#include "HeuristicAI.h"
#include "state/Player.h"
#include "engine/Engine.h"
#include "engine/CommandSet.h"
#include "state/State.h"
namespace ai {

    HeuristicAI::HeuristicAI(state::State* s) :Ai(s) {}
    
    /*int HeuristicAI::findBestMove(engine::CommandSet command, std::vector<int> poids, 
            int n, bool winType) {
        
        
        //int currentPoids = command.getPoids();
        //int bestVal = currentPoids; 
        
        int bestVal =0;
        
        int value;
        
        if (poids[n]>poids[n--]){
            return poids[n];
        }
        
        
        if (winType){
            value = findBestMove(command,poids,n++,false);
            bestVal = std::max(bestVal,value);
            return bestVal;
        } else{
            value = findBestMove(command,poids,n++,true);
            bestVal = std::min(bestVal,value);
            return bestVal;
       
        }
    }*/
    
    void HeuristicAI::run(state::State* s) {
        //sf::sleep(sf::seconds(5.f));
        //engine::CommandSet command;
        //int bestMove = 2;
        
        int dammage_IA = rand()%2;
        int dammage_Player = rand()%2;
        
        if(s->players[0]->getPosition().x > s->players[1]->getPosition().x+30){
        s->players[0]->notifyObservers(state::NOTHING_CHANGED);
        s->players[0]->setPosition(-1,0);
       
        } else{ 
            
            s->players[1]->decreaseHealth(dammage_IA);
            s->players[0]->decreaseHealth(dammage_Player);
            s->players[0]->notifyObservers(state::ATTACK_KICK);
        }
        
                   
        /*std::vector<int> poids_Noeuds = {
            
                            2,
              0,                              1,
        
        };
        
        int bestMove = findBestMove(command, poids_Noeuds, 0, false);
        
        switch (bestMove){
            case 0 :
                s->players[1]->setPosition(2,0);
                break;
            case 1 :
                
                s->players[1]->notifyObservers(state::ATTACK_KICK);
                break;
                
            case 2 :
                
                s->players[1]->setPosition(-2,0);
                break;      
        }*/
         
         
       
        
    }
        
    void HeuristicAI::run() {}
        
            
    
    
}