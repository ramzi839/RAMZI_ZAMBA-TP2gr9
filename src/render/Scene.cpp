/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "render/Scene.h"
#include "state/StateEventId.h"
#include <iostream>

using namespace std;
using namespace state;
using namespace render;
    
Scene::Scene(){
 
 
 }   
        

void Scene::stateChanged(state::StateEventId e){

    switch(e){
        
    case state::StateEventId::SMTH_CHANGED:
       
        
        break;
            
    default :
        cout<<"Nothing Changed"<<endl;
        break;

    }
}

void Scene::setBackground(){
    

}



