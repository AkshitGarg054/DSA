class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx==tx && sy==ty) return true;

        if(tx==ty) return false;

        if(tx<sx || ty<sy) return false;

        if(tx==sx) {
            if((ty-sy)%sx==0) return true;
            return false;
        }
        if(ty==sy) {
            if((tx-sx)%sy==0) return true;
            return false;
        }

        bool op=false;

        if(tx>ty) op= reachingPoints(sx,sy,tx-ty,ty);
        else  op= reachingPoints(sx,sy,tx,ty-tx);

        return op;
    }
};