#include"../../global.h"
#include"../entity.h"
void applyGravity (entity2D entity,float strength,bool notOnGround) {
     if (notOnGround) {
        entity.posy -= strength;	
     }
}
