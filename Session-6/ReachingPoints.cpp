// ReachingPoints
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx || ty<sy){
            return false;
        }
        if(sx == tx and sy == ty){
            return true;
        }
        if(sx == tx){
            return (ty-sy)%sx == 0;
        }
        if(sy == ty){
            return (tx-sx)%sy == 0;
        }
        
        if(ty>tx){
            return reachingPoints(sx,sy,tx,ty%tx);
        }
        else{
            return reachingPoints(sx,sy,tx%ty,ty);
        }
    }
};